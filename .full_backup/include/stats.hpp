#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <cstddef>

namespace logprof {

struct Histogram {
    // bucket_size in ms; map bucket_index -> count
    size_t bucket_size{10};
