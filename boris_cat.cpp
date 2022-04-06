#include <iostream>

using namespace std;

int main() {
    int n, l;
    int A[30] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        A[a] = b;
    }
    cin >> l;
    int begin = 0;
    int cnt_free = 0;
    for (int i = 0; i < 30 && cnt_free != l; i++) {
        if (A[i] == 0) {
            cnt_free++;
        } else {
            cnt_free = 0;
            begin = i + A[i];
            i = begin - 1;
        }
    }
    if (cnt_free == l) {
        cout << begin;
    } else {
        cout << -1;
    }
}