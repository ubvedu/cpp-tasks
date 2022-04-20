#include <iostream>

using std::cout;
using std::endl;

const unsigned int N = 2;
const int left[N] = {1, 2}; // command code 1
const int right[N] = {2, 3}; // command code 2
const int back[N] = {3, 4}; // command code 3
const int meow[N] = {4, 5}; // command code 4

void recognize(int *data_start, int *data_end, int *command, int **frame) {
    int matched[4] = {0};
    for (int i = 0; i < data_end - data_start; i++) {
        matched[0] = data_start[i] == left[matched[0]] ? matched[0] + 1 : 0;
        matched[1] = data_start[i] == right[matched[1]] ? matched[1] + 1 : 0;
        matched[2] = data_start[i] == back[matched[2]] ? matched[2] + 1 : 0;
        matched[3] = data_start[i] == meow[matched[3]] ? matched[3] + 1 : 0;
        for (int j = 0; j < 4; j++) {
            if (matched[j] >= N) {
                *command = j + 1;
                *frame = data_start + i - (int) N + 1;
                return;
            }
        }
    }
    *command = 0;
}

int main() {
    const int L = 21;
    int mindstream[L] = {1, 2, 3, 4, 5};
    int command = -1;
    int *frame = mindstream;
    int *end = mindstream + L;
    while (command) {
        recognize(frame, end, &command, &frame);
        if (!command) break;
        switch (command) {
            case 1:
                cout << "left ";
                break;
            case 2:
                cout << "right ";
                break;
            case 3:
                cout << "back ";
                break;
            case 4:
                cout << "MEOOOOW ";
                break;
        }
        frame += N;
    }
    cout << endl;
    return 0;
}