#ifndef MAPLAP2_0_TIMER_HPP
#define MAPLAP2_0_TIMER_HPP

#include <chrono>
#include <stdio.h>

class Timer {
private:

    const char* format_string = "Timer : %f .\n";
    double time_pass = 0;
    std::chrono::time_point<std::chrono::steady_clock> last;

public:

    Timer() noexcept;
    Timer(const char* object) noexcept;

    void start() noexcept;
    void stop() noexcept;

    void print();
    void zero() noexcept;

};


#endif //MAPLAP2_0_TIMER_HPP
