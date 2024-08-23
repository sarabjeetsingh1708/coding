#include <iostream>

using namespace std;


class Node {
public:
    int value;
    Node* next;

    Node(int val) {
        value=val;
        next=nullptr;
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
            cout << "empty stack" << endl;
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
            cout << "empty stack" << endl;
            return -1; 
        }
        return topNode->value;
    }
};


class QueueNode {
public:
    int value;
    QueueNode* next;

    QueueNode(int val){
        value=val;
        next=nullptr;
    } 
};


class Queue {
private:
    QueueNode* frontNode;
    QueueNode* backNode;

public:
   Queue() {
    frontNode = nullptr;
    backNode = nullptr;
}

    bool isEmpty() {
        return frontNode == nullptr;
    }

    void enqueue(int val) {
        QueueNode* newNode = new QueueNode(val);
        if (isEmpty()) {
            frontNode = backNode = newNode;
        } else {
            backNode->next = newNode;
            backNode = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "empty Queue" << endl;
            return -1; 
        }
        int dequeue = frontNode->value;
        QueueNode* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        return dequeue;
    }

    int peek() {
        if (isEmpty()) {
            cout << "empty Queue" << endl;
            return -1; 
        }
        return frontNode->value;
    }
};
int main() {
    
    Stack stack;

    
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element of stack " << stack.top() << endl;

    
    cout << "Popping elements : ";
    while (!stack.isEmpty()) {
        cout << stack.pop() << " ";
    }
    cout << endl;

    
    Queue queue;

    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);

    
    cout << "peek element of queue " << queue.peek() << endl;


    cout << "Dequeuing elements from the queue: ";
    while (!queue.isEmpty()) {
        cout << queue.dequeue() << " ";
    }
    cout << endl;

    return 0;
}