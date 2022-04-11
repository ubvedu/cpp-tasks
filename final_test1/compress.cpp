
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int * compress(int ** matrix, int n, int m) {
    int * array = new int[n * 3];
    int k = 0;
    for (int i = 0; i < n; i++) {
        int non_zero = 0;
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                non_zero++;
                if (non_zero > 3) {
                    delete[] array;
                    return nullptr;
                }
                array[k++] = matrix[i][j];
            }
        }
        if (non_zero < 3) {
            delete[] array;
            return nullptr;
        }
    }
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
    delete[] a;

    if (!compressed) return 0;

    for (int i = 0; i < n * 3; i++)
        cout << compressed[i] << " ";
    cout << endl;

    delete[] compressed;
    return 0;
}