#include<iostream>
#include<vector>
using namespace std;
bool checkprefixsuffixsum(vector<int> & v){
    int totalsum = 0;
    for(int i=0;i<v.size();i++){
        totalsum+=v[i];
    }
    int prefixsum=0;
    for(int i=0;i<v.size();i){
        prefixsum+=v[i];
        int suffixsum=totalsum-prefixsum;
        if (suffixsum==prefixsum){
            return true;
        }

    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<checkprefixsuffixsum(v)<<endl;
    return 0;

}