#include<iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

int height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* z = x->right;

    x->right = y;
    y->left = z;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* z = y->left;

    y->left = x;
    x->right = z;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int Balance(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

Node* insert(Node* node, int key) {
    if (node == nullptr)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = Balance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
Node * minvalueNode(Node * node) {
    Node * current = node;
    while (current -> left != NULL) {
      current = current -> left;
    }
    return current;
  }
Node* deleteNode(Node* node, int v) {
    if (node == nullptr) {
      return nullptr;
    }
    else if (v < node->key) {
      node->left = deleteNode(node->left, v);
    }
    else if (v > node->key) {
      node->right = deleteNode(node->right, v);
    }
    else {
      if (node->left == nullptr) {
        Node* temp = node->right;
        delete node;
        return temp;
      } else if (node->right == nullptr) {
        Node* temp = node->left;
        delete node;
        return temp;
      } else {
        Node* temp = minvalueNode(node->right);
        node->key = temp->key;
        node->right = deleteNode(node->right, temp->key);
      }
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int bf = Balance(node);

    if (bf > 1 && Balance(node->left) >= 0)
      return rightRotate(node);
    else if (bf > 1 && Balance(node->left) < 0) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
    else if (bf < -1 && Balance(node->right) <= 0)
      return leftRotate(node);
    else if (bf < -1 && Balance(node->right) > 0) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }

    return node;
}
Node * Search(Node * node, int val) {
    if (node == NULL || node -> key == val)
      return node;

    else if (val < node -> key){
      return Search(node -> left, val);
    }
    else{
      return Search(node -> right, val);
  }

}
void inorder(Node* node) {
    if (node) {
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }
}
int main() {
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    inorder(root);
    cout << endl;

    int valueToSearch = 30;
    Node* foundNode = Search(root, valueToSearch);
    if (foundNode)
        cout << " value founded" << valueToSearch << " in the AVL tree." << endl;
    else
        cout << "Value " << valueToSearch << " not found in the AVL tree." << endl;

    int valueToDelete = 30;
    root = deleteNode(root, valueToDelete);

    cout << "Inorder traversal of the AVL tree after deletion:" << endl;
    inorder(root);
    cout << endl;

    return 0;
} 

