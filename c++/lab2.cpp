#include <iostream>
using namespace std;


int Stairs( int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    return Stairs(n - 1) + Stairs(n - 2);
}

int main() {
    int q;
    cin>>q;
    cout << "Ways to climb " << Stairs(q) << endl;  
   
    return 0;
}
