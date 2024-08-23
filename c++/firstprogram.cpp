


#include <iostream>
using namespace std;
 

int binary(int arr[], int l, int h, int find)
{
    while (l <= h) {
        int mid = (l + h) / 2;
 
        
        if (arr[mid] == find)
            return mid;
 
        
        if (arr[mid] > find)
            return binary(arr,l,mid-1,find);
 
        
        return binary(arr,mid+1,h,find);
    }
 
    
    return -1;
}
 

int main(void)
{
    int arr[] = { 1,3,5,7,9 };
    int find = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binary(arr, 0, n - 1, find);
    cout<<result;
    
    return 0;
}

