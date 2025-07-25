#pragma once
#include <chrono>
#include <functional>

namespace logprof {
class ScopedTimer {
public:
    explicit ScopedTimer(std::function<void(std::chrono::microseconds)> cb)
      : cb_(std::move(cb)), start_(std::chrono::high_resolution_clock::now()) {}
    ~ScopedTimer() {
