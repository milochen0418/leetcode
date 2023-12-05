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
    //https://leetcode.com/problems/two-sum-bsts
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> set1, set2;
        function<void(TreeNode*,unordered_set<int>&)> dfs = [&](TreeNode* root,unordered_set<int>&s) {
            if(!root) return;
            s.insert(root->val);
            dfs(root->left,s);
            dfs(root->right,s);
        };
        dfs(root1, set1);
        dfs(root2, set2);
        for(auto &v:set1) 
            if (set2.find(target-v) != set2.end()) return true;
        
        return false;
    }
};