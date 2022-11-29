#include "simple_chrono.h"
#include <chrono>

int main()
{
    ScopeChronometer<std::chrono::microseconds> c;
    int my_array[100000];
    for (int i = 0; i < 100000; i++){
        my_array[i] = i;
    }
    return 0;
}