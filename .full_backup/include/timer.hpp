#pragma once
#include <chrono>
#include <functional>

namespace logprof {
class ScopedTimer {
public:
    explicit ScopedTimer(std::function<void(std::chrono::microseconds)> cb)
