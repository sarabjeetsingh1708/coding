#include <iostream>
using namespace std;

int addition(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0) {
    return a + b + c + d + e;
}

int subtract(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0) {
    return a - b - c - d - e;
}

int multiply(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0) {
    return a * b * c * d * e;
}

int divide(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0) {
    if (b == 0 || c == 0 || d == 0 || e == 0) {
        cout << "Cannot divide by zero." << endl;
        return 0;
    }
    return ((((a / b) / c) / d) / e);
}

int main() {
    string op_type;
    cin >> op_type;
    int n;
    cin >> n;

    int a = 0, b = 0, c = 0, d = 0, e = 0;

    for (int i = 0; i < n; i++) {
        switch (i) {
            case 0:
                cin >> a;
                break;
            case 1:
                cin >> b;
                break;
            case 2:
                cin >> c;
                break;
            case 3:
                cin >> d;
                break;
            case 4:
                cin >> e;
                break;
            default:
                break;
        }
    }

    if (op_type == "add") {
        cout << addition(a, b, c, d, e) << endl;
    } else if (op_type == "subtract") {
        cout << subtract(a, b, c, d, e) << endl;
    } else if (op_type == "multiply") {
        cout << multiply(a, b, c, d, e) << endl;
    } else if (op_type == "divide") {
        cout << divide(a, b, c, d, e) << endl;
    } else {
        cout << "Invalid operation type." << endl;
    }

    return 0;
}
