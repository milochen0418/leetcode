/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    //https://leetcode.com/problems/convert-bst-to-greater-tree
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) return nullptr;
        root->right = convertBST(root->right);
        sum += root->val;
        root->val = sum;
        root->left = convertBST(root->left);
        return root;
    }
};