#pragma once
#include <string_view>
#include <vector>

namespace logprof {
std::vector<std::string_view> split_sv(std::string_view s, char delim);
}


