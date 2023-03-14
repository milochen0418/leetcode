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
    //https://leetcode.com/problems/sum-root-to-leaf-numbers
public:
    typedef long long ll;
    int sumNumbers(TreeNode* root) {
        ll ans = 0;
        function<void(TreeNode*, ll)> dfs = [&](TreeNode*root,ll val) {
            if(!root) return;
            ll new_val = val*10+(ll)root->val;
            if(!root->left && !root->right) ans+=new_val;
            dfs(root->left, new_val);
            dfs(root->right,new_val);                
            
        };
        dfs(root,0);
        return (int) ans;
    }
};