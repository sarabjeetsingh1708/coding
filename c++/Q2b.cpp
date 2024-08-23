#include <iostream>


using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val) {
        value = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* topNode;

public:
    Stack() {
        topNode = nullptr;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "empty Stack" << endl;
            return -1;
        }
        int pop = topNode->value;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return pop;
    }

    int top() {
        if (isEmpty()) {
            cout << "empty Stack" << endl;
            return -1;
        }
        return topNode->value;
    }
};

void circulararray( int array[], int n) {
    Stack panda;

    int i = 0;
    while (i < n) {
        while (!panda.isEmpty() && array[i] > array[panda.top()]) {
            cout << array[i] << " ";
            panda.pop();
        }
        panda.push(i);
        i++;
    }

    while (!panda.isEmpty()) {
        cout << -1 << " ";
        panda.pop();
    }

    cout << endl;
}

int main() {
    int array[] = {1, 2, 3, 4, 3};
    int n = sizeof(array) / sizeof(array[0]);

    cout << "output: ";
    circulararray(array, n);

    return 0;
}
