#include <iostream>
#include <vector>

using namespace std;

struct HashNode {
    int key;
    string value;
    HashNode* next;

    HashNode(int k, string v) : key(k), value(v), next(nullptr) {}
};

class Hashtable {
private:
    int size;
    vector<HashNode*> table;

    int hashFunction(int key) {
        return key % size;
    }

public:
    Hashtable(int size) : size(size), table(size, nullptr) {}

    void insertClosedchaining(int key, string value) {
        int index = hashFunction(key);
        if (table[index] == nullptr) {
            table[index] = new HashNode(key, value);
        } else {
            HashNode* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new HashNode(key, value);
        }
    }

    void insertOpenLinear(int key, string value) {
        int index = hashFunction(key);
        while (table[index] != nullptr) {
            index = (index + 1) % size;
        }
        table[index] = new HashNode(key, value);
    }

    string searchOpenLinear(int key) {
        int index = hashFunction(key);
        while (table[index] != nullptr) {
            if (table[index]->key == key) {
                return table[index]->value;
            }
            index = (index + 1) % size;
        }
        return "Not found";
    }

    void deleteOpenLinear(int key) {
        int index = hashFunction(key);
        while (table[index] != nullptr) {
            if (table[index]->key == key) {
                table[index] = nullptr;
                return;
            }
            index = (index + 1) % size;
        }
    }

    string searchClosedchaining(int key) {
        int index = hashFunction(key);
        HashNode* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return "Not found";
    }

    void deleteClosedchaining(int key) {
        int index = hashFunction(key);
        if (table[index] == nullptr) {
            return;
        }
        if (table[index]->key == key) {
            table[index] = table[index]->next;
            return;
        }
        HashNode* prev = nullptr;
        HashNode* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                prev->next = current->next;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            cout << "Bucket " << i << ": ";
            HashNode* current = table[i];
            while (current != nullptr) {
                cout << "(" << current->key << ", " << current->value << ") -> ";
                current = current->next;
            }
            cout << "nullptr" << endl;
        }
    }

    ~Hashtable() {
        for (int i = 0; i < size; ++i) {
            HashNode* current = table[i];
            while (current != nullptr) {
                HashNode* next = current->next;
                delete current;
                current = next;
            }
        }
    }
};

int main() {
    int tableSize = 10;
    Hashtable hashTable(tableSize);

    hashTable.insertClosedchaining(5, "Value 5");
    hashTable.insertClosedchaining(15, "Value 15");
    hashTable.insertClosedchaining(25, "Value 25");

    hashTable.insertOpenLinear(6, "Value 6");
    hashTable.insertOpenLinear(16, "Value 16");
    hashTable.insertOpenLinear(26, "Value 26");

    cout << "Hashtable after insertion:" << endl;
    hashTable.display();

    cout << "\nSearch results:" << endl;
    cout << "Search using Closed Addressing (Chaining):" << endl;
    cout << "Key 5: " << hashTable.searchClosedchaining(5) << endl;
    cout << "Key 15: " << hashTable.searchClosedchaining(15) << endl;
    cout << "Key 25: " << hashTable.searchClosedchaining(25) << endl;
    cout << "Key 6: " << hashTable.searchOpenLinear(6) << endl;
    cout << "Key 16: " << hashTable.searchOpenLinear(16) << endl;
    cout << "Key 26: " << hashTable.searchOpenLinear(26) << endl;
    cout << "Key 10: " << hashTable.searchOpenLinear(10) << endl;

    cout << "\nDelete operations:" << endl;
    hashTable.deleteClosedchaining(5);
    hashTable.deleteOpenLinear(16);

    cout << "\nHashtable after deletion:" << endl;
    hashTable.display();

    return 0;
}


