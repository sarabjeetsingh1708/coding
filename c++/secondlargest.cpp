#include<iostream>
using namespace std;
int largestelementindex(int array[],int size){
    int max=INT64_MIN;
    int maxindex=-1;
    for (int i = 0; i < size;i++){
        if(array[i]>max){
            max=array[i];
            maxindex=i;

        }

    }
    return maxindex;

}

int main(){

    int array[]={2,3,5,7,6,1};
    int indexoflargest=largestelementindex(array,6);
    array[indexoflargest]=-1;
    int indexofsecondlargest=largestelementindex(array,6);
    cout<<array[indexofsecondlargest]<<endl;
    
    return 0;
}