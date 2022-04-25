#ifndef CPP_TASKS_TREE_H
#define CPP_TASKS_TREE_H

using value_t = int;

struct Node {
    Node *less;
    Node *greater;
    value_t value;
};

void print(Node *root);

Node *insert(Node *root, value_t value);
Node *remove(Node *root, value_t value);
Node *rotate_left(Node *root);
Node *rotate_right(Node *root);
Node *rotate_right_left(Node *root);
Node *rotate_left_right(Node *root);

#endif //CPP_TASKS_TREE_H
