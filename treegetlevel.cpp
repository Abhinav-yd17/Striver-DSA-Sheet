#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getLevel(TreeNode* root, int target) {
        if (root == NULL) return -1;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->val == target)
                    return level;

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
            level++;
        }
        return -1;  
    }
};