#include <iostream>

using namespace std;

class Node {
public:
    int student;
    Node* leftNode;
    Node* rightNode;
 
    Node(int data) {
        student = data;
        leftNode = rightNode = nullptr;
    }
};
 
class BinaryTree {
public:
    Node* rootNode;
    
    bool isSibling(Node* list, Node* aNode, Node* bNode) {
        if (list == nullptr)
            return false;
 
        return ((list->leftNode == aNode && list->rightNode == bNode) ||
                (list->leftNode == bNode && list->rightNode == aNode) ||
                isSibling(list->leftNode, aNode, bNode) ||
                isSibling(list->rightNode, aNode, bNode));
    }
 
    int level(Node* list, Node* pointer, int lev) {
        if (list == nullptr)
            return 0;
 
        if (list == pointer)
            return lev;
 
        int l = level(list->leftNode, pointer, lev + 1);
        if (l != 0)
            return l;
 
        return level(list->rightNode, pointer, lev + 1);
    }
 
    bool isCousin(Node* list, Node* aNode, Node* bNode) {
        return ((level(list, aNode, 1) == level(list, bNode, 1)) &&
                (!isSibling(list, aNode, bNode)));
    }
};

int main() {
    BinaryTree node;
    node.rootNode = new Node(1);
    node.rootNode->leftNode = new Node(2);
    node.rootNode->rightNode = new Node(3);
    node.rootNode->leftNode->leftNode = new Node(4);
    node.rootNode->leftNode->rightNode = new Node(5);
    node.rootNode->leftNode->rightNode->rightNode = new Node(15);
    node.rootNode->rightNode->leftNode = new Node(6);
    node.rootNode->rightNode->rightNode = new Node(7);
    node.rootNode->rightNode->leftNode->rightNode = new Node(8);

    Node* node1, *node2;
    node1 = node.rootNode->leftNode->leftNode;
    node2 = node.rootNode->rightNode->rightNode;
    if (node.isCousin(node.rootNode, node1, node2))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}


