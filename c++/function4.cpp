#include <iostream>
using namespace std;
int sub(int, int);
int main() {
int difference;

difference = sub(200, 100);
cout << difference << endl;
return 0;
}

int sub(int x, int y) {
return (x - y);
}