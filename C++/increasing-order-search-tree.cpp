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
    // https://leetcode.com/problems/increasing-order-search-tree
public:
    TreeNode* ans = nullptr;
    TreeNode* curr = nullptr;
    TreeNode* increasingBST(TreeNode* root) {
        ans = new TreeNode(root->val);
        curr = ans;
        travelBST(root);
        ans = ans->right;
        return ans;
    }
    void travelBST(TreeNode* root){
        if(root == nullptr) return;
        travelBST(root->left);
        curr->right = new TreeNode(root->val);
        curr = curr->right;
        travelBST(root->right);
    }
};