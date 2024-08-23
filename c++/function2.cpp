#include<iostream>
using namespace std;
int addition(int p, int q) {
int add = p + q;
return add;
}
int main() {
int p = 40;
int q = 60;

int answer = addition(p,q);
cout<<("Sum is: ")<< answer;
} 