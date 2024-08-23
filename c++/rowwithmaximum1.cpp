#include <iostream>
#include <vector>
using namespace std;
int maximumonesrow(vector<vector<int>> & v){
    int maxones=INT8_MIN;
    int maxrows=-1;
    int columns=v[0].size();
    for (int i=0; i<v.size(); i++){
        for(int j=0; j<columns; j++){
            if (v[i][j]==1){
                int numberofones=columns-j;
                if(numberofones>maxones) {
                    maxones=numberofones;
                    maxrows=i;
                }
            }   break;

        }
        return maxrows;
    }



}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vec(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>vec[i][j];

        }
    }
    int res=maximumonesrow(vec);
    cout<<res<<endl;
    return 0;
}
