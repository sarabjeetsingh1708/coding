#include<iostream>
using namespace std;

class stack{
    
    int* arr;
    int top;
    int n;

    public:
    stack(){
        arr=new int[n];
        top=-1;
    }
    void push(int x){
        if(top=n-1){
            cout<<"stack overflow"<<endl;
            return;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"no element to pop"<<endl;
            return;
        }
        top --;
    }
    int Top(){
        if(top==-1){
            cout<<"no element in stack"<<endl;
            return -1;
        }
        return arr[top];
    }
    bool empty(){
        return top==-1;
    }
};

int main(){
    return 0;
}

