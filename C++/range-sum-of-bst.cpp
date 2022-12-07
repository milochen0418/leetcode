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
    //https://leetcode.com/problems/range-sum-of-bst
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int val = (root->val<low || root->val>high)?0:root->val;
        return val+rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
    }
};