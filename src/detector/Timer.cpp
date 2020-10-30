#include "detector/Timer.hpp"

Timer::Timer() noexcept {
    start();
}

Timer::Timer(const char* object) noexcept : format_string(object) {
    start();
}

void Timer::start() noexcept {
    last = std::chrono::steady_clock::now();
}

void Timer::stop() noexcept {
    time_pass += (std::chrono::steady_clock::now() - last).count();
    start();
}

void Timer::print() {
    printf(format_string, time_pass / 1000000000.0);
    fflush(stdout);
}

void Timer::zero() noexcept {
    time_pass = 0;
}