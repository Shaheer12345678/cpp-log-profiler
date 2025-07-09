#include "stats.hpp"
#include <algorithm>

namespace logprof {

void Histogram::add(long long latency_ms) {
    size_t idx = static_cast<size_t>(latency_ms < 0 ? 0 : latency_ms) / bucket_size;
    buckets[idx]++;
