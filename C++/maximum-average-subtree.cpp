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
    //https://leetcode.com/problems/maximum-average-subtree/
public:
    double maximumAverageSubtree(TreeNode* root) {
        unordered_map<TreeNode*,int> sums; //sum of this subtree
        unordered_map<TreeNode*,int> total; //total number of node of this subtree
        function<int(TreeNode*)> dfs_sums = [&](TreeNode* root) {
            if(root == NULL) return 0;
            sums[root] = root->val + dfs_sums(root->left) +dfs_sums(root->right);
            return sums[root];
        };
        function<int(TreeNode*)> dfs_total = [&](TreeNode* root) {
            if(root == NULL) return 0;
            total[root] = 1 + dfs_total(root->left) +dfs_total(root->right);
            return total[root];
        };
        dfs_sums(root);
        dfs_total(root);
        double ans = 0.0f;
        for(auto &[k,v]:total) ans = max(ans, (double)sums[k]/(double)total[k]);        
        return ans;
    }
};