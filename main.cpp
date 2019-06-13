#include <fmt/format.h>
#include "format_iter.h"

int main(){
    std::vector<double> v{0, 1, 2, 42, 42.42, 1.0 / 42.0};
    std::vector<std::vector<double>> vv {v, {0.1, 0.2}};
    fmt::print("default format: {}\n", v);
    fmt::print("scientific : {:.4e}\n", v);
    fmt::print("vector of vectors: {:+7.5f}\n", vv);
    return 0;
}
