#include "tree.h"
#include <iostream>

using namespace std;

Node *new_node(value_t value) {
    return new Node{nullptr, nullptr, value};
}

Node *insert(Node *root, value_t value) {
    if (root == nullptr) {
        return new_node(value);
    }
    if (value < root->value) {
        root->less = insert(root->less, value);
    } else if (value > root->value) {
        root->greater = insert(root->greater, value);
    }
    return root;
}

Node *remove(Node *root, value_t value) {
    if (root == nullptr) {
        return root;
    }
    if (value < root->value) {
        root->less = remove(root->less, value);
    } else if (value > root->value) {
        root->greater = remove(root->greater, value);
    }
    return root;
}

Node *rotate_left(Node *root) {
    if (root == nullptr) {
        return root;
    }
    auto greater = root->greater;
    if (greater == nullptr) {
        return root;
    }
    root->greater = greater->less;
    greater->less = root;
    return greater;
}

Node *rotate_right(Node *root) {
    if (root == nullptr) {
        return root;
    }
    auto less = root->less;
    if (less == nullptr) {
        return root;
    }
    root->less = less->greater;
    less->greater = root;
    return less;
}

Node *rotate_right_left(Node *root) {
    if (root == nullptr) {
        return root;
    }
    root->greater = rotate_right(root->greater);
    return rotate_left(root);
}

Node *rotate_left_right(Node *root) {
    if (root == nullptr) {
        return root;
    }
    root->less = rotate_left(root->less);
    return rotate_right(root);
}

void print(Node *root) {
    if (root == nullptr) {
        return;
    }
    if (root->less != nullptr) {
        cout << "(";
        print(root->less);
        cout << ") ";
    }
    cout << root->value;
    if (root->greater != nullptr) {
        cout << " (";
        print(root->greater);
        cout << ")";
    }
}
