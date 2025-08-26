#pragma once
#include <chrono>
#include <functional>

namespace logprof {
class ScopedTimer {
public:
    explicit ScopedTimer(std::function<void(std::chrono::microseconds)> cb)
      : cb_(std::move(cb)), start_(std::chrono::high_resolution_clock::now()) {}
    ~ScopedTimer() {
        auto end = std::chrono::high_resolution_clock::now();
        cb_(std::chrono::duration_cast<std::chrono::microseconds>(end - start_));
    }
private:
    std::function<void(std::chrono::microseconds)> cb_;
    std::chrono::high_resolution_clock::time_point start_;
};
}


