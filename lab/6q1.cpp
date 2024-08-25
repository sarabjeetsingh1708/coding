#include <iostream>
using namespace std;



class Node {
public:
    int storage;
    Node* next;
};


void rotate(Node** headpointer, int a) {
    if (a == 0 || *headpointer == nullptr) {
        return; 
    }

    
    int totalnode = 0;
    Node* current = *headpointer;
    for (; current != nullptr; current = current->next) {
    totalnode++;
    }

    
    a %= totalnode;

   
    if (a == 0) {
        return;
    }

    
    current = *headpointer;
    int i;
    while (current != nullptr && i < a - 1) {
    current = current->next;
    ++i;
    }

    
    Node*newhead = current->next;
    current->next = nullptr; 
    current =newhead;
    for (; current->next != nullptr; current = current->next) {
    
    }
    current->next = *headpointer;
    *headpointer =newhead;
}


void push(Node** headpointer, int new_storage) {
    Node* newnode = new Node();
    newnode->storage = new_storage;
    newnode->next = *headpointer;
    *headpointer = newnode;
}


void printList(Node* node) {
    for (; node != nullptr; node = node->next) {
    cout << node->storage << " ";
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    for (int i = 5; i >= 1; --i) {
        push(&head, i);
    }

    cout << "given linked list  ";
    printList(head);

    int a = 2; 
    rotate(&head, a);

    cout << "rotated linked list ";
    printList(head);

    
    return 0;
}
