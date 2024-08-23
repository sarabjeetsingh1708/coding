#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int max(int A, int B, int C) {
    return max(max(A, B), C);
}


int maxcross(int arr[], int q, int m, int h) {
    int left = INT_MIN;
    int sum = 0;
    int i=m;
    while (i >= q) {
    sum += arr[i];
    left = max(left, sum);
    --i;
}

    int right = INT_MIN;
    sum = 0;
    int u = m + 1;
    while (u <= h) {
    sum += arr[u];
    right = max(right, sum);
    ++u;
}



    return max(left + right, left, right);
}


int maxsum(int arr[], int f, int h) {
    if (f == h) {
        return arr[f]; 
    }

    int mid = (f + h) / 2; 

    
    return max(maxsum(arr, f, mid), maxsum(arr, mid + 1, h), maxcross(arr, f, mid, h));
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
   

    int n1 = sizeof(arr) / sizeof(arr[0]);
    
    
    cout << " maximum sum is " << maxsum(arr, 0, n1 - 1) << endl;
   
    return 0;
}

//the time complexity of divide and conquer is O(nlog(n))
