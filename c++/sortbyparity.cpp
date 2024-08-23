#include <iostream>
#include<vector>
using namespace std;
void sortArrayByParity(vector<int>& a) {
    int i = 0, j = a.size()-1;
    while(i < j) {
        if(a[i] % 2 == 1 && a[j] % 2 == 0) {
            swap(a[i], a[j]);
            i++, j--;
        }
        if(a[i] % 2 == 0) {
            i++;
        }
        if(a[j] % 2 == 1) {
            j--;
        }
    }
    return ;
}
int main(){
    int n;
    cin>>n;
    vector<int> a;
    for (int i=0; i<n; i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    sortArrayByParity(a);
    for (int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}