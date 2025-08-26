#include "tokenize.hpp"
using namespace std;

namespace logprof {
vector<string_view> split_sv(string_view s, char delim) {
    vector<string_view> out;
    size_t start = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == delim) {
            out.emplace_back(s.substr(start, i - start));
            start = i + 1;
        }
    }
    out.emplace_back(s.substr(start));
    return out;
}
}


