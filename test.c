#include "simple_chrono.h"

int main()
{
    chronometer_t c = start_ms_chronometer();

    int my_array[1000000];
    for (int i = 0; i < 1000000; i++){
        my_array[i] = i;
    }
    stop_ms_chronometer(c);

    return 0;
}