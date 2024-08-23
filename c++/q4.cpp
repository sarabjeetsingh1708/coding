#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> minmax(const vector<int>& arr) {
    int n = arr.size();
    vector<int> final;

    for (int size = 1; size <= n; ++size) {
        int M_Val = INT_MIN;

        for (int i = 0; i <= n - size; ++i) {
            int m_Val = INT_MAX;

            for (int j = i; j < i + size; ++j) {
                m_Val = min(m_Val, arr[j]);
            }

            M_Val = max(M_Val, m_Val);
        }

        final.push_back(M_Val);
    }

    return final;
}

int main() {
    
    vector<int> example = {3, 1, 2, 4};
    vector<int> final = minmax(example);

    cout << "final array: [";
    for (int i = 0; i < final.size(); ++i) {
        cout << final[i];
        if (i < final.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
