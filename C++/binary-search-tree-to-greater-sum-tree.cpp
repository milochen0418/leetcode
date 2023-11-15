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
    //https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<TreeNode*> v;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if(!root) return;
            v.push_back(root);
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
        sort(v.begin(), v.end(), [&](auto lhs, auto rhs){
           return lhs->val > rhs->val; 
        });
        int n = v.size();
        for(int i = 1;i<n;i++) 
            v[i]->val += v[i-1]->val;
        return root;
        
    }
};