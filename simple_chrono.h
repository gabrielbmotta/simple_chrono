#ifndef SIMPLE_CHRONO
#define SIMPLE_CHRONO

#ifdef __cplusplus

#include <chrono>
#include <ostream>
#include <iostream>
#include <string>

//==============================================================================

constexpr const char* getUnits(std::chrono::nanoseconds){
    return "ns";
}

constexpr const char* getUnits(std::chrono::microseconds){
    return "us";
}

constexpr const char* getUnits(std::chrono::milliseconds){
    return "ms";
}

constexpr const char* getUnits(std::chrono::seconds){
    return "s";
}

//==============================================================================

template <typename T>
class ScopeChronometer
{
public:
    ScopeChronometer(const char* name = "")
    : _name(name), _start_time(std::chrono::steady_clock::now()){
    }

    ~ScopeChronometer(){
        auto end = std::chrono::steady_clock::now();
        if(!_name.empty()){
            std::cout << _name << " ";
        }
        std::cout << std::chrono::duration_cast<T>(end - _start_time).count() << getUnits(_time_meas) << "\n";
	}

private:
    std::string _name;
    std::chrono::time_point<std::chrono::steady_clock> _start_time;
    T _time_meas;
};

#endif

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

typedef void* chronometer_t;

EXTERNC chronometer_t start_ms_chronometer();
EXTERNC void stop_ms_chronometer(chronometer_t chronometer);

EXTERNC chronometer_t start_us_chronometer();
EXTERNC void stop_us_chronometer(chronometer_t chronometer);

EXTERNC chronometer_t start_ns_chronometer();
EXTERNC void stop_ns_chronometer(chronometer_t chronometer);

#endif
