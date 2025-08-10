#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <cstddef>

namespace logprof {

struct Histogram {
    // bucket_size in ms; map bucket_index -> count
    size_t bucket_size{10};
    std::unordered_map<size_t, size_t> buckets;
    void add(long long latency_ms);
    std::vector<std::pair<size_t,size_t>> sorted() const; // (bucket_index, count)
};

