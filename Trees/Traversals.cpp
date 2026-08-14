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

// PREORDER

class Solution {
public:
    void preorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;

        ans.push_back(root->val);

        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};

//INORDER       

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;

        inorder(root->left, ans);

        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
}; 

// POSTORDER

class Solution {
public:
    void postorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;

        postorder(root->left, ans);
        postorder(root->right, ans);

        ans.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};