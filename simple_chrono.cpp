#include "simple_chrono.h"
#include <chrono>

chronometer_t start_ms_chronometer(){
    return new ScopeChronometer<std::chrono::milliseconds>();
}

void stop_ms_chronometer(chronometer_t chronometer){
    auto *c = static_cast<ScopeChronometer<std::chrono::milliseconds>*>(chronometer);
    delete c; 
}

chronometer_t start_us_chronometer(){
    return new ScopeChronometer<std::chrono::microseconds>();
}

void stop_us_chronometer(chronometer_t chronometer){
    auto *c = static_cast<ScopeChronometer<std::chrono::microseconds>*>(chronometer);
    delete c; 
}

chronometer_t start_ns_chronometer(){
    return new ScopeChronometer<std::chrono::nanoseconds>();
}

void stop_ns_chronometer(chronometer_t chronometer){
    auto *c = static_cast<ScopeChronometer<std::chrono::nanoseconds>*>(chronometer);
    delete c; 
}