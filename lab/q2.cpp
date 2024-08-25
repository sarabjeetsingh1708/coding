#include <iostream>
using namespace std;

int randomisedquicksort(int arr[],int first,int last){
    
    int pivotindex = rand() % (last - first + 1) + first;
    swap(arr[pivotindex], arr[last]);
    int pivot=arr[last];
    cout<<"with pivot  "<<pivot<<"  ";
    int i=first-1;
    int j=first;
    for(;j<last;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    
    swap(arr[i+1],arr[last]);
    cout<<"after iteration ";
    for (int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    cout<<endl;
    return i+1;


}


void quicksort(int arr[],int first,int last ){
    
    if(first>=last){
        return;
    }
    int pi=randomisedquicksort(arr,first,last);
    quicksort(arr,first,pi-1);
    quicksort(arr,pi+1,last);
    
}
int main(){
    int arr[]={9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0, n-1);
    cout<<"finally sorted array  ";
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}