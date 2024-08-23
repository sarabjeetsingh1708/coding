#include <iostream>
#include <vector>
using namespace std;
vector<int> runningsum(vector<int> & v){
    int n=v.size();
    for(int i=1;i<n;i++){
        v[i]=v[i-1]+v[i];
    }
    return v;
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    runningsum(v);
    return 0;
}