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
