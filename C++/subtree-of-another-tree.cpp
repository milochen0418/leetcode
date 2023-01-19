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
    //https://leetcode.com/problems/subtree-of-another-tree
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }
    bool dfs(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(same(root, subRoot)) return true;
        if(dfs(root->left, subRoot)) return true;
        if(dfs(root->right, subRoot)) return true;
        return false;
    }
    
    bool same(TreeNode* root1, TreeNode* root2) {
        if(root1==root2) return true;
        if(!root1 != !root2) return false;
        if(root1->val != root2->val) return false;
        if(!same(root1->left, root2->left)) return false;
        if(!same(root1->right, root2->right)) return false;
        return true;
    }
};