#include<iostream>
#include<vector>
#include<algorithm> // Include the algorithm header for reverse function
using namespace std;

vector<int> sortedSquares(vector<int>& a) {
    int n = a.size(), i = 0, j = n - 1;
    vector<int> ans(n); // Initialize ans vector with the correct size
    int k = n - 1; // Index for filling the ans vector from the end

    while (i <= j) {
        if (abs(a[i]) < abs(a[j])) {
            a[j] *= a[j];
            ans[k--] = a[j--];
        } else {
            a[i] *= a[i];
            ans[k--] = a[i++];
        }
    }
    
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        a[i] = element; // Corrected vector initialization
    }

    vector<int> result = sortedSquares(a); // Call the sortedSquares function
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
