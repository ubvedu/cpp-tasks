#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
};

Node *create_ring(int n) {
    auto first = new Node{1, nullptr};
    auto last = first;
    for (int i = 2; i <= n; i++) {
        last->next = new Node{i, first};
        last = last->next;
    }
    return last;
}

void remove_next(Node *node) {
    auto next = node->next;
    node->next = next->next;
    delete next;
}

int main() {
    int n, k;
    cin >> n >> k;
    auto ring = create_ring(n);
    int i = 1;
    while (ring->next != ring) {
        if (i % k == 0) {
            remove_next(ring);
            i = 1;
        } else {
            ring = ring->next;
            i++;
        }
    }
    cout << ring->value;
    delete ring;
    return 0;
}
