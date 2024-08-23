#include <iostream>
#include <vector>

using namespace std;


void merge(vector<int>& array, int left, int mid, int right) {
    
    int n1 = mid - left + 1;
    int n2 = right - mid;

   
    vector<int> leftarray(n1), rightarray(n2);

    
    for (int i = 0; i < n1; i++)
        leftarray[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        rightarray[j] = array[mid + 1 + j];

    

    
    int i = 0, j = 0;

   
    int k = left;

    
    while (i < n1 && j < n2) {
        if (leftarray[i] <= rightarray[j]) {
            array[k] = leftarray[i];
            i++;
        } else {
            array[k] = rightarray[j];
            j++;
        }
        k++;
    }

    
    while (i < n1) {
        array[k] = leftarray[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        array[k] = rightarray[j];
        j++;
        k++;
    }
}


void mergesort(vector<int>& arr) {
    int n = arr.size(); 
    
    for (int currsize = 1; currsize <= n - 1; currsize *= 2) {
        
        for (int left = 0; left < n - 1; left += 2 * currsize) {
           
            int mid = min(left + currsize - 1, n - 1);

            int right = min(left + 2 * currsize - 1, n - 1);

           
            merge(arr, left, mid, right);
        }
    }
}


void printarray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << ",";
    }
    cout << endl;
}


int main() {
     int n;
    cin>>n;
     vector<int> array(n);
    for(int i=0; i<n; i++){
        cin>>array[i];
    }

    mergesort(array);
    cout << "sorted array print without recursion ";
    for (int i = 0; i < n - 1; ++i) {
        cout << array[i] << ",";
    }
    cout << array[n - 1] << endl;

    cout << "Sorted array print with recursion is ";
    printarray(array);
    return 0;
}
