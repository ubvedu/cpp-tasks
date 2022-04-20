
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int * compress(int ** matrix, int n, int m) {
    int * array = new int[n * 3];
    int k = 0;
    bool three_non_zeros = true;
    for (int i = 0; i < n && three_non_zeros; i++) {
        int non_zero = 0;
        for (int j = 0; j < m && three_non_zeros; j++) {
            if (matrix[i][j] != 0) {
                if (++non_zero > 3) {
                    three_non_zeros = false;
                } else {
                    array[k++] = matrix[i][j];
                }
            }
        }
        if (non_zero < 3) {
            three_non_zeros = false;
        }
    }
    if (!three_non_zeros) {
        delete[] array;
        array = nullptr;
    }
    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
    return array;
}

int main() {
    int n, m;
    cin >> n >> m;
    int ** a = new int * [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int * compressed = compress(a, n, m);

    if (!compressed) return 0;

    for (int i = 0; i < n * 3; i++)
        cout << compressed[i] << " ";
    cout << endl;

    delete[] compressed;
    return 0;
}