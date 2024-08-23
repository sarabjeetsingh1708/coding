#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maxSubArraySum(int arr[], int l, int h) {
    if (l == h) {
        return arr[l]; // Base case: single element
    }

    int m = (l + h) / 2; // Midpoint

    // Return the maximum of three cases:
    // 1. Maximum subarray sum in the left half
    // 2. Maximum subarray sum in the right half
    // 3. Maximum subarray sum that crosses the midpoint
    return max(maxSubArraySum(arr, l, m), maxSubArraySum(arr, m + 1, h), maxCrossingSum(arr, l, m, h));
}


int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout  << maxsubarraySum(arr, 0, n - 1) << endl;
    return 0;
}