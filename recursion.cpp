#include <iostream>

using namespace std;

unsigned shift_(unsigned exp, unsigned shift) {
    if (exp >> shift) return shift_(exp, shift + 1);
    return shift;
}

int pow_(int man, unsigned exp, int acc, unsigned shift) {
    if (!shift) return acc;
    if ((exp >> (shift - 1)) % 2) return pow_(man, exp, man * acc * acc, shift - 1);
    return pow_(man, exp, acc * acc, shift - 1);
}

int pow(int man, unsigned exp) {
    return pow_(man, exp, 1, shift_(exp, 0));
}

int main() {
    int a;
    unsigned b;
    cin >> a >> b;
    cout << pow(a, b) << endl;
    return 0;
}

