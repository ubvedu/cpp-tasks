#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
};

Node *read_list() {
    int a;
    cin >> a;
    if (a) {
        return new Node{a, read_list()};
    }
    return nullptr;
}

void print_list_values(Node *node) {
    while (node != nullptr) {
        cout << node->value << " ";
        node = node->next;
    }
}

Node *reverse_list(Node *first) {
    auto second = first->next;
    first->next = nullptr;
    if (second == nullptr) {
        return first;
    }
    auto last = reverse_list(second);
    second->next = first;
    return last;
}

void delete_list(Node *node) {
    if (node == nullptr) {
        return;
    }
    delete_list(node->next);
    delete node;
}

int main() {
    Node* list = read_list();
    list = reverse_list(list);
    print_list_values(list);
    delete_list(list);
    return 0;
}
