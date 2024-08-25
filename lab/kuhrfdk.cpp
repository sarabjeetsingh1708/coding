#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Construct the binary tree from level-order input
TreeNode* constructTree(vector<int>& levelOrder) {
    if (levelOrder.empty()) return nullptr;
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(levelOrder[0]);
    q.push(root);
    int i = 1;
    while (!q.empty() && i < levelOrder.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < levelOrder.size() && levelOrder[i] != -1) {
            curr->left = new TreeNode(levelOrder[i]);
            q.push(curr->left);
        }
        i++;
        if (i < levelOrder.size() && levelOrder[i] != -1) {
            curr->right = new TreeNode(levelOrder[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// Perform BFS to find the sequence of impacted junctions
vector<vector<int>> findImpactedSequence(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> levelNodes;
        for (int i = 0; i < levelSize; i++) {
            TreeNode* curr = q.front();
            q.pop();
            levelNodes.push_back(curr->val);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        result.push_back(levelNodes);
    }
    return result;
}

int main() {
    // Input: 12 13 10 N N 14 15 N N N N 21 24 22 23 (Level order input)
    vector<int> levelOrder = {12, 13, 10, -1, -1, 14, 15, -1, -1, -1, -1, 21, 24, 22, 23};
    TreeNode* root = constructTree(levelOrder);

    // Find the impacted sequence
    vector<vector<int>> impactedSequence = findImpactedSequence(root);

    // Print the result
    for (const auto& level : impactedSequence) {
        for (int node : level) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
