#include <cstdint>
#include <iostream>

using namespace std;

uint32_t get_results(uint32_t channel) {
    static uint32_t calls = 0;
    calls++;
    if (calls > 25) return static_cast<uint32_t>(-1);

    static uint32_t min = 10, max = 255760;
    static uint32_t min_channel = 50, max_channel = 250;
    static uint32_t zero = 100000;

    if (channel <= min_channel)
        return static_cast<uint32_t>(zero - channel * ((double) zero - min) / min_channel);
    if (channel <= max_channel)
        return static_cast<uint32_t>(min + ((double) channel - min_channel) * ((double) max - min) /
                                           ((double) max_channel - min_channel));
    if (channel <= 360)
        return static_cast<uint32_t>(max - ((double) channel - max_channel) * ((double) max - zero) /
                                           ((double) 360 - max_channel));
    return static_cast<uint32_t>(-1);
}

void detect_in(uint32_t i1, uint32_t d1, uint32_t i2, uint32_t d2, uint32_t &i_max, uint32_t &max) {
    auto i = (i1 + i2) / 2;
    auto d = get_results(i + 1) - get_results(i);
    if (d1 > 0 && d > 0 && d2 > 0) {

    }
}

void detect() {

}

int main() {
    detect();
    return 0;
}
