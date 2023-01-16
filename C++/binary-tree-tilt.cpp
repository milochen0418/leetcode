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
    //https://leetcode.com/problems/binary-tree-tilt
public:
    int ans = 0;
    unordered_map<TreeNode*,int> sum_mp;
    int findTilt(TreeNode* root) {
        get_sum(root);
        dfs(root);
        return ans;
    }
    int get_sum(TreeNode* root) {
        if(!root) return 0;
        if(sum_mp.find(root) != sum_mp.end() ) return sum_mp[root];
        sum_mp[root] = root->val + get_sum(root->left) + get_sum(root->right);
        return sum_mp[root];
    }
    void dfs(TreeNode* root) {
        if(!root) return;
        root->val = abs(get_sum(root->left) - get_sum(root->right));
        ans+=root->val;
        dfs(root->left);
        dfs(root->right);
    }
};