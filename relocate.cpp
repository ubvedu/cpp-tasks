#include <iostream>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;

int *run(int init_size, int &length, int &size, bool &done, int &copied) {
    auto trace = new int[size];
    auto p = init_size / 2;
    auto seed = chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();
    // auto seed = 1647855781908497108ll;
    cout << "random seed " << seed << endl;
    default_random_engine generator(seed);
    uniform_real_distribution<float> distrib(0, 1);
    while (0 < p && p < init_size - 1) {
        trace[length++] = p - init_size / 2;
        if (distrib(generator) < 0.5) {
            p--;
        } else {
            p++;
        }
        if (length >= size) {
            auto size_new = (size * 3) / 2;
            auto trace_new = new (nothrow) int[size_new];
            if (!trace_new) {
                done = false;
                return trace;
            }
            for (int j = 0; j < size; j++) {
                trace_new[j] = trace[j];
            }
            copied += size;
            delete[] trace;
            trace = trace_new;
            size = size_new;
        }
    }
    done = true;
    trace[length++] = p - init_size / 2;
    return trace;
}

int main() {
    auto h = 1000;
    auto init_size = 2 * h + 1;
    int size = init_size, length = 0, copied = 0;
    bool done;
    auto trace = run(init_size, length, size, done, copied);
    cout << "длина следа: " << length << endl;
    cout << "выделено ячеек: " << size << endl;
    cout << "успешно: " << boolalpha << done << endl;
    cout << "скопировано элементов: " << copied << endl;
    // cout << "след: ";
    // for (int i = 0; i < length; i++) {
    //     cout << trace[i] << " ";
    // }
    // cout << endl;
    return 0;
}
