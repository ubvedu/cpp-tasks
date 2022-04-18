#include <iostream>
#include <cstddef>
#include <string>

using namespace std;

size_t levenstein_down_(string a, string b, size_t m, size_t n, size_t **mem) {
    if (m == 0) return n;
    if (n == 0) return m;
    if (mem[m - 1][n - 1]) return mem[m - 1][n - 1];
    auto insert = levenstein_down_(a, b, m, n - 1, mem) + 1;
    auto remove = levenstein_down_(a, b, m - 1, n, mem) + 1;
    auto replace = levenstein_down_(a, b, m - 1, n - 1, mem) + (a[m - 1] != b[n - 1]);
    mem[m - 1][n - 1] = min(min(insert, remove), replace);
    return mem[m - 1][n - 1];
}

size_t levenstein_down(string a, string b) {
    size_t m = a.length(), n = b.length();
    auto mem = new size_t*[m];
    for (size_t i = 0; i < m; i++) {
        mem[i] = new size_t[n] {0};
    }
    auto result = levenstein_down_(a, b, m, n, mem);
    for (size_t i = 0; i < m; i++) {
        delete[] mem[i];
    }
    delete[] mem;
    return result;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << levenstein_down(a, b) << endl;
    return 0;
}