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
    //https://leetcode.com/problems/binary-tree-inorder-traversal
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        if(root == nullptr) return v;
        s.push(root);
        while(!s.empty()) {
            TreeNode* e = s.top();
            if(e->left != nullptr && e->left->val != INT_MIN) {
                s.push(e->left);    
            } else {
                v.push_back(e->val);
                e->val = INT_MIN;
                s.pop();
                if(e->right != nullptr && e->right->val != INT_MIN) {
                    s.push(e->right);
                }
            }
        }
        return v;
    }
};