#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};
class Solution {
public:
    void dfs(TreeNode* node, int level, vector<int>& ds) {
        if (node == NULL) return;
        if (level == ds.size()) ds.push_back(node->val);
        dfs(node->right, level + 1, ds);
        dfs(node->left, level + 1, ds);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ds;
        dfs(root, 0, ds);
        return ds;
    }
};
