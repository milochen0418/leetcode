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
    //https://leetcode.com/problems/binary-tree-paths/
public:
    vector<string> vs; 
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr) return vs;
        string rootStr = to_string(root->val); 
        btp(root, rootStr);
        return vs;
    }
    void btp(TreeNode* root, string &str) {
        if(root->left == nullptr && root->right == nullptr) { 
            vs.push_back(str);
        }
        if(root->left != nullptr) {
            string newstr=str + "->" + to_string(root->left->val);
            btp(root->left, newstr);
            
        } 
        if(root->right != nullptr) {
            string newstr=str + "->" + to_string(root->right->val);
            btp(root->right, newstr);
        }
    }
};