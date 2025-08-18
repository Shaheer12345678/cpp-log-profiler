#include "stats.hpp"
#include <algorithm>

namespace logprof {

void Histogram::add(long long latency_ms) {
    size_t idx = static_cast<size_t>(latency_ms < 0 ? 0 : latency_ms) / bucket_size;
    buckets[idx]++;
}

std::vector<std::pair<size_t,size_t>> Histogram::sorted() const {
    std::vector<std::pair<size_t,size_t>> v(buckets.begin(), buckets.end());
    std::sort(v.begin(), v.end(), [](auto& a, auto& b){ return a.first < b.first;});
    return v;
}

std::vector<std::pair<std::string,size_t>> top_k(const std::vector<std::string>& items, size_t k) {
    std::unordered_map<std::string,size_t> freq;
    for (auto& s : items) freq[s]++;
    std::vector<std::pair<std::string,size_t>> v(freq.begin(), freq.end());
    std::partial_sort(v.begin(), v.begin() + std::min(k, v.size()), v.end(),
        [](auto& a, auto& b){ return a.second > b.second; });
    if (v.size() > k) v.resize(k);
    return v;
}

