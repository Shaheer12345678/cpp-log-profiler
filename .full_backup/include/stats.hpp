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

std::vector<std::pair<std::string,size_t>> top_k(const std::vector<std::string>& items, size_t k);

}
