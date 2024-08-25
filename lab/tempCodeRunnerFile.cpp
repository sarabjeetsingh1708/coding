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

    bool areSiblings(Node* currentNode, Node* firstNode, Node* secondNode) {
        if (currentNode == nullptr)
            return false;
        
        return ((currentNode->leftNode == firstNode && currentNode->rightNode == secondNode) ||
                (currentNode->leftNode == secondNode && currentNode->rightNode == firstNode) ||
                areSiblings(currentNode->leftNode, firstNode, secondNode) ||
                areSiblings(currentNode->rightNode, firstNode, secondNode));
    }

    int findLevel(Node* currentNode, Node* targetNode, int level) {
        if (currentNode == nullptr)
            return 0;
        
        if (currentNode == targetNode)
            return level;
        
        int leftResult = findLevel(currentNode->leftNode, targetNode, level + 1);
        if (leftResult != 0)
            return leftResult;
        
        return findLevel(currentNode->rightNode, targetNode, level + 1);
    }

    bool areCousins(Node* currentNode, Node* firstNode, Node* secondNode) {
        return ((findLevel(currentNode, firstNode, 1) == findLevel(currentNode, secondNode, 1)) &&
                (!areSiblings(currentNode, firstNode, secondNode)));
    }

    void findNodeWithValue(Node* currentNode, int value, Node*& resultNode) {
        if (currentNode == nullptr)
            return;

        if (currentNode->student == value) {
            resultNode = currentNode;
            return;
        }

        findNodeWithValue(currentNode->leftNode, value, resultNode);
        findNodeWithValue(currentNode->rightNode, value, resultNode);
    }
};

int main() {
    BinaryTree tree;
    tree.rootNode = new Node(1);
    tree.rootNode->leftNode = new Node(2);
    tree.rootNode->rightNode = new Node(3);
    tree.rootNode->leftNode->leftNode = new Node(4);
    tree.rootNode->leftNode->rightNode = new Node(5);
    tree.rootNode->leftNode->rightNode->rightNode = new Node(15);
    tree.rootNode->rightNode->leftNode = new Node(6);
    tree.rootNode->rightNode->rightNode = new Node(7);
    tree.rootNode->rightNode->leftNode->rightNode = new Node(8);

    int value1, value2;
    cout << "Enter value for node1: ";
    cin >> value1;
    cout << "Enter value for node2: ";
    cin >> value2;

    Node* node1 = nullptr;
    Node* node2 = nullptr;
    tree.findNodeWithValue(tree.rootNode, value1, node1);
    tree.findNodeWithValue(tree.rootNode, value2, node2);

    if (node1 == nullptr || node2 == nullptr) {
        cout << "One or both nodes not found in the tree." << endl;
        return 0;
    }

    if (tree.areCousins(tree.rootNode, node1, node2))
        cout << "Yes, "<< endl;
    else
        cout << "No, " << endl;

    return 0;
}
