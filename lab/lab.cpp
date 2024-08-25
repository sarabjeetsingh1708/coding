#include<iostream>
#include<vector>
using namespace std;

class Heap {
private:
    vector<int> heap;


    void heapifyUp(int i) {
        int parent = (i - 1) / 2;
        while (i > 0 && heap[i] < heap[parent]) {
            swap(heap[i], heap[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

   
    void heapifyDown(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int small = i;
        if (left < heap.size() && heap[left] < heap[i]) {
            small = left;
        }
        if (right < heap.size() && heap[right] < heap[small]) {
            small = right;
        }
        if (small != i) {
            swap(heap[i], heap[small]);
            heapifyDown(small);
        }
    }

public:
    
    Heap() {}

    
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    
    void delet() {
        if (heap.empty()) {
            cout << "Heap is empty. Nothing to delete." << endl;
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    
    int extractMin() {
        if (heap.empty()) {
            cout << "Heap is empty." << endl;
            return -1; 
        }
        int minElement = heap[0];
        delet();
        return minElement;
    }

    
    void heapify(vector<int>& arr) {
        heap = arr;
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    vector<int> heapSort(vector<int>& arr) {
        heapify(arr);
        vector<int> sorted;
        while (!heap.empty()) {
            sorted.push_back(extractMin());
        }
        return sorted;
    }

   
    vector<int> getHeap() {
        return heap;
    }
};

int main() {
    Heap minHeap;

    minHeap.insert(50);
    minHeap.insert(55);
    minHeap.insert(53);
    minHeap.insert(52);
    minHeap.insert(54);

    cout << " Heap before deletion: ";
    for (int num : minHeap.getHeap()) {
        cout << num << " ";
    }
    cout << endl;

    minHeap.delet();

    cout << " Heap after deletion: ";
    for (int num : minHeap.getHeap()) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Extracted Min: " << minHeap.extractMin() << endl;

    // Heap sort
    vector<int> arr = { 5, 2, 9, 1, 7 };
    vector<int> sortedArr = minHeap.heapSort(arr);

    cout << "Sorted Array using Heap Sort: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
