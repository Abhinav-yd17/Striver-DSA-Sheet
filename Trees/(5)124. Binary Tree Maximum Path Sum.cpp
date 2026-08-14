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
    int maxPathSum(TreeNode* root) {                                                                                    
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }
private:
    int maxPathDown(TreeNode* node, int &maxi) {
        if (node == nullptr) return 0;

        int left = max(0, maxPathDown(node->left, maxi));
        int right = max(0, maxPathDown(node->right, maxi));

        maxi = max(maxi, left + right + node->val);

        return max(left, right) + node->val;
    }
};