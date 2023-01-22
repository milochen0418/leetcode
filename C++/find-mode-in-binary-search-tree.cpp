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
    //https://leetcode.com/problems/find-mode-in-binary-search-tree
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp;
        int maxcnt = 0;
        function<void(TreeNode*)> dfs = [&](TreeNode*root){
            if(!root) return;
            dfs(root->left);
            maxcnt=max(maxcnt, ++mp[root->val]);
            dfs(root->right);
        };
        dfs(root);
        vector<int> ans;
        for(auto &[val,cnt]:mp) 
            if(cnt == maxcnt) ans.push_back(val);
        return ans;
    }
};