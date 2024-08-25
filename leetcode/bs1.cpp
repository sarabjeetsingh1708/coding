#include<iostream>
using namespace std;

int firstoccurrence(int arr[], int n, int k) {
    int s = 0, e = n - 1;
    int ans = -1;
    

    while (s <= e) {
        int mid = s + (e - s) / 2; // Update mid within the loop
        if (arr[mid] == k) {
            ans = mid; // Found the element
            e = mid - 1; // Move to the left half to find the first occurrence
        }
        else if (k > arr[mid]) {
            s = mid + 1; // Search in the right half
        }
        else {
            e = mid - 1; // Search in the left half
        }
    }
    return ans;
}
int lasttoccurrence(int arr[], int n, int k) {
    int s = 0, e = n - 1;
    int ans = -1;
    

    while (s <= e) {
        int mid = s + (e - s) / 2; // Update mid within the loop
        if (arr[mid] == k) {
            ans = mid; // Found the element
            s = mid + 1; // Move to the left half to find the first occurrence
        }
        else if (k > arr[mid]) {
            s = mid + 1; // Search in the right half
        }
        else {
            e = mid - 1; // Search in the left half
        }
    }
    return ans;
}

int main() {
    int arr[5] = {1, 2, 3, 3, 5};
    cout << "First occurrence of 3 is at index " << firstoccurrence(arr, 5, 3) << endl;
    cout << "Last occurrence of 3 is at index " << lasttoccurrence(arr, 5, 3) << endl;
    return 0;
}
