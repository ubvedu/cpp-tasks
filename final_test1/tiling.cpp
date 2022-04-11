
#include <iostream>

using namespace std;

int main() {
    unsigned long long n;
    cin >> n;
    auto tiles = 0ull;
    while (n > 0) {
        n /= 2;
        tiles += n;
    }
    cout << tiles;
}
