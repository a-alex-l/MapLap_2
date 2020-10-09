#include "detector/Timer.hpp"

Timer::Timer() noexcept {
    last = std::chrono::steady_clock::now();
}

Timer::Timer(const char* object) noexcept : format_string(object) {
    last = std::chrono::steady_clock::now();
}

void Timer::start() noexcept {
    last = std::chrono::steady_clock::now();
}

void Timer::stop() noexcept {
    time_pass += (std::chrono::steady_clock::now() - last).count();
    last = std::chrono::steady_clock::now();
}

void Timer::print() {
    printf(format_string, time_pass);
}

void Timer::zero() noexcept {
    time_pass = 0;
}