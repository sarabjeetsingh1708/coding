#include <iostream>
#include <vector>

using namespace std;

vector<int> mergesort(const vector<int>& firsthalf, const vector<int>& secondhalf) {
    int a = firsthalf.size();
    int b = secondhalf.size();
    int n = a + b;

    int i = 0, j = 0, k = 0;
    vector<int> final(n);

    while (i < firsthalf.size() && j < secondhalf.size()) {
        if (firsthalf[i] < secondhalf[j]) {
            final[k] = firsthalf[i];
            i++;
        } else {
            final[k] = secondhalf[j];
            j++;
        }
        k++;
    }

    while (i < firsthalf.size()) {
        final[k] = firsthalf[i];
        i++;
        k++;
    }

    while (j < secondhalf.size()) {
        final[k] = secondhalf[j];
        j++;
        k++;
    }

    return final;
}

int main() {
    vector<int> array = {1, 2, 3, 4, 5, 6, 7};
    vector<int> array2 = {8, 9, 10};
    vector<int> output = mergesort(array, array2);
    int n = output.size();

    for (int i = 0; i < n; i++) {
        cout << output[i] << "  ";
    }

    return 0;
}
