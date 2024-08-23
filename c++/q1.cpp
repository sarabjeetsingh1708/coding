#include<iostream>
using namespace std;
void towerofhanoi(int n, char a, char b, char c, char d){
    if (n == 1) {
        cout << a << " -> " << d << endl;
        return;
    }
    towerofhanoi(n - 2, a, c, d, b);
    cout <<  a<< " -> " << c<< endl;
    cout <<  a<< " -> " << d << endl;
    cout <<  c<< " -> " << d <<endl;
    towerofhanoi(n - 2, b, a, c, d);
}
int main() {
    int num;
    
    cin >> num;

    towerofhanoi(num, 'a', 'b', 'c', 'd');

    return 0;
}
