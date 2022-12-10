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
    //https://leetcode.com/problems/maximum-product-of-splitted-binary-tree
    //article https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/discuss/2896985/C%2B%2B-or-DFS-and-the-tricky-big-number
public:
    /* 
    if you use unsigned long long to figure out solution in this problem, 
    that's enough for all caculation. But the only problem is that the problem 
    request you to return int.  
    */    
    typedef unsigned long long ull;    
    unordered_map<TreeNode*,ull> mp;
    int maxProduct(TreeNode* root) {
        ull total = sum_dfs(root), ans = 0;
        for(auto &[node, sum]: mp) ans = max(ans, sum* (total-sum));
        return (int)(ans%((ull)(1e9+7)));
    }
    ull sum_dfs(TreeNode *root){
        if(!root) return 0;
        mp[root] = root->val + sum_dfs(root->left) + sum_dfs(root->right);
        return mp[root];
    } 
};