#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Structure to represent a junction
struct Junction {
    int id;
    vector<Junction*> neighbors;
    bool affected;  // Flag to track if the junction is affected by the blast
};

// Perform BFS to find the sequence of affected junctions
vector<vector<int>> findAffectedSequence(Junction* root) {
    vector<vector<int>> result;
    queue<Junction*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel;

        for (int i = 0; i < levelSize; ++i) {
            Junction* curr = q.front();
            q.pop();

            if (!curr->affected) {
                curr->affected = true;
                currentLevel.push_back(curr->id);

                for (Junction* neighbor : curr->neighbors) {
                    if (!neighbor->affected) {
                        q.push(neighbor);
                    }
                }
            }
        }

        if (!currentLevel.empty()) {
            result.push_back(currentLevel);
        }
    }

    return result;
}

int main() {
    // Create the junctions and set their neighbors
    unordered_map<int, Junction> junctions;
    junctions[12] = {12, {}, false};
    junctions[13] = {13, {}, false};
    junctions[10] = {10, {}, false};
    junctions[14] = {14, {}, false};
    junctions[15] = {15, {}, false};
    junctions[21] = {21, {}, false};
    junctions[24] = {24, {}, false};
    junctions[22] = {22, {}, false};
    junctions[23] = {23, {}, false};

    junctions[12].neighbors = {&junctions[13], &junctions[10]};
    junctions[13].neighbors = {&junctions[14], &junctions[15]};
    junctions[14].neighbors = {&junctions[21], &junctions[24]};
    junctions[15].neighbors = {&junctions[22], &junctions[23]};

    // Set the target node
    Junction* target = &junctions[14];

    // Find the affected sequence
    vector<vector<int>> affectedSequence = findAffectedSequence(target);

    // Print the result
    for (const vector<int>& level : affectedSequence) {
        for (int id : level) {
            cout << id << " ";
        }
        cout << endl;
    }

    return 0;
}
