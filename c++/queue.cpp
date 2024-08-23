#include<iostream>
using namespace std;
class queue{
    int* arr;
    int front;
    int back;
    int n;

    public:
    queue(){
        arr=new int[n];
        front=-1;
        back=-1; 
    }
    void push(int x){
        if(back==n-1){
            cout<<"queue overflow: "<<endl;
            return;
        }
        back ++;
        arr[back]=x;

        if (front==-1){
            front++;
        }
    }
    void pop(){
        if(front==-1||front>back){
            cout<<"no elemnets in queue"<<endl;
            return ;

        }
        front++;
    }
    int peek(){
        if(front==-1||front>back){
            cout<<"no elemnets in queue"<<endl;
            return ;

        }
        return arr[front];
     }
};