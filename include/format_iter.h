#include <vector>
#include <fmt/core.h>

namespace fmt{
    template<class T>
    struct formatter<std::vector<T>> {
        formatter<T> item_fmt;
        constexpr auto parse(basic_parse_context<char>& ctx)
            -> decltype(ctx.begin()) {
            return item_fmt.parse(ctx);
        }

        template<typename FormatContext>
        auto format(const std::vector<T> &d, FormatContext &ctx) -> decltype(ctx.out()) {
            auto ret = ctx.begin();
            auto str = [&ret](std::string text){
                           ret = std::copy(text.begin(), text.end(), ret);
                       };
            str("[");
            size_t idx = 0;
            for (auto i = d.begin(); i != d.end(); ++i){
                if (idx){
                    str(", ");
                }
                if (idx > 10){
                    str("...");
                    break;
                }

                ret = item_fmt.format(*i, ctx);
                ++idx;
            }
            str("]");
            return ret;
        }

    };
}

