#include <iostream>
#include <chrono>
#include <random>

using namespace std;

long long seed = chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();
default_random_engine generator(seed);
uniform_real_distribution<double> distrib(0., 1.);

void fill_random(int * A, int n) {
    for (int i = 0; i < n; i++)
        A[i] = distrib(generator) * n;
}

void print(int * A, int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

bool check_sorted(int const * A, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (A[i] > A[i + 1]) {
            return false;
        }
    }
    return true;
}

void bubble_sort(int A[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (A[j + 1] < A[j]) {
                auto tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
            }
}

int partition(int A[], int l, int r, int pivot) {
    while (A[l] < pivot) l++;
    while (A[r] > pivot) r--;
    while (l < r) {
        auto tmp = A[l];
        A[l++] = A[r];
        A[r--] = tmp;
        while (A[l] < pivot) l++;
        while (A[r] > pivot) r--;
    }
    return r;
}

void quick_sort_(int A[], int l, int r) {
    if (l >= r) return;
    auto m = partition(A, l, r, (A[l] + A[r]) / 2);
    quick_sort_(A, l, m);
    quick_sort_(A, m + 1, r);
}

void quick_sort(int A[], int n) {
    quick_sort_(A, 0, n);
}

void merge_sort_(int * A, int * B, int l, int r) {
    if (r - l <= 1) return;
    auto m = (l + r) / 2;
    merge_sort_(A, B, l, m);
    merge_sort_(A, B, m, r);
    auto i = l;
    auto j = m;
    for (int k = l; k < r; k++) {
        if (A[i] < A[j]) {
            B[k] = A[i++];
            if (i >= m) while (k < r) B[++k] = A[j++];
        } else {
            B[k] = A[j++];
            if (j >= r) while (k < r) B[++k] = A[i++];
        }
    }
    for (int k = l; k < r; k++) A[k] = B[k];
}

void merge_sort(int * A, int n) {
    int * B = new int[n];
    merge_sort_(A, B, 0, n);
    delete[] B;
}

void print_heap(int *A, int n) {
    int i, j = 0;
    for (i = 0; i < n; i++) {
        cout << A[i] << " ";
        if (i >= j) {
            cout << endl;
            j += j + 2;
        }
    }
    if (i < j) {
        cout << endl;
    }
}

void shift_down(int * A, int n, int i) {
    if (i * 2 + 1 >= n) return;
    auto j = i * 2 + 2 < n && A[i * 2 + 2] > A[i * 2 + 1] ? i * 2 + 2 : i * 2 + 1;
    if (A[i] < A[j]) {
        auto tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
        shift_down(A, n, j);
    }
}

void heapify(int * A, int n) {
    for (int i = (n - 1) / 2; i >= 0; i--)
        shift_down(A, n, i);
}

void heap_sort(int * A, int n) {
    heapify(A, n);
    for (int i = n - 1; i >= 0; i--) {
        auto tmp = A[i];
        A[i] = A[0];
        A[0] = tmp;
        shift_down(A, i, 0);
    }
}

int main() {
    int n = 50;
    int * A = new int[n];
    fill_random(A, n);
    print(A, n);
    heap_sort(A, n);
    print(A, n);
    if (check_sorted(A, n)) cout << "sorted!" << endl;
    else cout << "not sorted.";
    delete[] A;
    return 0;
}
