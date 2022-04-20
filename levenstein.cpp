#include <iostream>
#include <cstddef>
#include <string>

using namespace std;

size_t get_mem(size_t m, size_t n, size_t **mem) {
    if (m == -1) return n + 1;
    if (n == -1) return m + 1;
    return mem[m][n];
}

void print_transform(string a, string b, size_t m, size_t n, size_t **mem) {
    bool print = true;
    if (m != 0 && n != 0) {
        auto insert = get_mem(m - 1, n - 2, mem) + 1;
        auto remove = get_mem(m - 2, n - 1, mem) + 1;
        auto replace = get_mem(m - 2, n - 2, mem) + (a[m - 1] != b[n - 1]);
        if (insert <= remove && insert <= replace) {
            print_transform(a, b, m, n - 1, mem);
        } else if (remove <= insert && remove <= replace) {
            print_transform(a, b, m - 1, n, mem);
        } else {
            print_transform(a, b, m - 1, n - 1, mem);
            print = a[m - 1] != b[n - 1];
        }
    } else if (m == 0 && n != 0) {
        print_transform(a, b, m, n - 1, mem);
    } else if (m != 0) {
        print_transform(a, b, m - 1, n, mem);
    }
    if (print) {
        cout << b.substr(0, n) << a.substr(m, a.length() - m) << endl;
    }
}

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
    auto mem = new size_t *[m];
    for (size_t i = 0; i < m; i++) {
        mem[i] = new size_t[n]{0};
    }
    auto result = levenstein_down_(a, b, m, n, mem);
    print_transform(a, b, m, n, mem);
    for (size_t i = 0; i < m; i++) {
        delete[] mem[i];
    }
    delete[] mem;
    return result;
}

size_t levenstein_up(string a, string b) {
    auto mem = new size_t *[a.length()];
    size_t i, j;
    for (i = 0; i < a.length(); i++) {
        mem[i] = new size_t[b.length()];
        for (j = 0; j < b.length(); j++) {
            auto insert = get_mem(i, j - 1, mem) + 1;
            auto remove = get_mem(i - 1, j, mem) + 1;
            auto replace = get_mem(i - 1, j - 1, mem) + (a[i] != b[j]);
            mem[i][j] = min(min(insert, remove), replace);
        }
    }
    print_transform(a, b, i, j, mem);
    auto result = mem[i - 1][j - 1];
    for (i = 0; i < b.length(); i++) {
        delete[] mem[i];
    }
    delete[] mem;
    return result;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << levenstein_up(a, b) << endl;
    return 0;
}