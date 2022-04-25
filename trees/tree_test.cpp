#include <iostream>
#include <fstream>
#include <chrono>
#include "tree.h"

using namespace std;

int main() {
    Node *tree;
    for (int k : {5, 3, 4, 1, 2}) {
        tree = insert(tree, k);
    }
    tree = rotate_left_right(tree);
    print(tree);
}

void test_tree_output() {
    const size_t n = 1000000;
    ofstream file("trees/simple.csv");
    if (!file.is_open()) {
        cout << "file error" << endl;
        return;
    }
    for (size_t i = 0; i < n; i++) {

    }
}

int64_t test_tree(value_t *values, size_t n) {
    auto start = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

}
