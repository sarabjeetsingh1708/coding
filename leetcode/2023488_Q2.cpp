#include<iostream>
#include<climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* Tree() {
    //hardcode input
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(18);

    return root;
}

bool isBST(Node* root, int min, int max) {
    if(root == NULL)
        return true;

    if(root->data >= min && root->data <= max) {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    } else
        return false;
}

int main() {
    Node* root = Tree();
    int decision = isBST(root, INT_MIN, INT_MAX);
    if(decision == 1)
        cout << "True";
    else
        cout << "False";

    return 0;
}
