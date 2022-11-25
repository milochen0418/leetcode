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
    //https://leetcode.com/problems/count-complete-tree-nodes/
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) 
            return 0;
        else 
            return 1+countNodes(root->left) + countNodes(root->right);
    }
};