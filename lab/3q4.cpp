#include <iostream>
#include <vector>

using namespace std;

class TaskAssignment {
private:
    vector<int> max_heap;
    vector<int> min_heap;
    vector<int> median_left;
    vector<int> median_right;

    void swapInt(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapifyUpMax(int idx) {
        while (idx > 0 && max_heap[(idx - 1) / 2] < max_heap[idx]) {
            swapInt(max_heap[(idx - 1) / 2], max_heap[idx]);
            idx = (idx - 1) / 2;
        }
    }

    void heapifyDownMax(int idx) {
        int n = max_heap.size();
        while (2 * idx + 1 < n) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int largest = idx;
            if (left < n && max_heap[left] > max_heap[largest]) {
                largest = left;
            }
            if (right < n && max_heap[right] > max_heap[largest]) {
                largest = right;
            }
            if (largest != idx) {
                swapInt(max_heap[idx], max_heap[largest]);
                idx = largest;
            } else {
                break;
            }
        }
    }

    void heapifyUpMin(int idx) {
        while (idx > 0 && min_heap[(idx - 1) / 2] > min_heap[idx]) {
            swapInt(min_heap[(idx - 1) / 2], min_heap[idx]);
            idx = (idx - 1) / 2;
        }
    }

    void heapifyDownMin(int idx) {
        int n = min_heap.size();
        while (2 * idx + 1 < n) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int smallest = idx;
            if (left < n && min_heap[left] < min_heap[smallest]) {
                smallest = left;
            }
            if (right < n && min_heap[right] < min_heap[smallest]) {
                smallest = right;
            }
            if (smallest != idx) {
                swapInt(min_heap[idx], min_heap[smallest]);
                idx = smallest;
            } else {
                break;
            }
        }
    }

public:
    TaskAssignment(const vector<int>& tasks) {
        for (int task_id : tasks) {
            max_heap.push_back(task_id);
            min_heap.push_back(task_id);
            heapifyUpMax(max_heap.size() - 1);
            heapifyUpMin(min_heap.size() - 1);
        }

        median_left.push_back(max_heap[0]);
        median_right.push_back(min_heap[0]);
    }

    int assignTask(int query) {
        int task_id = 0;
        if (query == 1) {
            task_id = max_heap[0];
            swapInt(max_heap[0], max_heap[max_heap.size() - 1]);
            max_heap.pop_back();
            heapifyDownMax(0);
        } else if (query == 2) {
            int k;
            cout << "Enter k: ";
            cin >> k;
            vector<int> temp;
            for (int i = 0; i < k; ++i) {
                temp.push_back(min_heap[0]);
                swapInt(min_heap[0], min_heap[min_heap.size() - 1]);
                min_heap.pop_back();
                heapifyDownMin(0);
            }
            task_id = temp.back();
            for (int id : temp) {
                min_heap.push_back(id);
                heapifyUpMin(min_heap.size() - 1);
            }
        } else if (query == 3) {
            int total_tasks = median_left.size() + median_right.size() - 2;
            if (total_tasks % 2 == 0) {
                task_id = min_heap[0] + 2;
            } else {
                task_id = max_heap[0] + 2;
            }
        }

        median_left.push_back(max_heap[0]);
        median_right.push_back(min_heap[0]);

        return task_id;
    }
};

int main() {
    vector<int> tasks = {34, 56, 12, 44, 10};
    TaskAssignment assignment(tasks);

    int query;
    cout << "Enter query (1, 2, or 3): ";
    cin >> query;

    int result = assignment.assignTask(query);
    cout << "Output: " << result << endl;

    return 0;
}
