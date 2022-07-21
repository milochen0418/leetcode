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
public:
    unordered_map<TreeNode*, int> dp;//height of TreeNode
    bool isBalanced(TreeNode* root) {
        //dp[nullptr] = 0;
        //return dfs(root);
        return !(ddfs(root) == -1);
    }

    int ddfs(TreeNode* node) {
        if(!node) return 0;
        int r = node->right?ddfs(node->right):0;
        if(r==-1) return -1;
        int l = node->left?ddfs(node->left):0;
        if(l==-1) return -1;        
        if(abs(l-r)>1) return -1;
        return 1+max(l,r);
    }

    bool dfs(TreeNode* node) {
        if(!node) return true;
        if(abs(h_dfs(node->left)-h_dfs(node->right))<=1) {
            return dfs(node->left) && dfs(node->right);
        } 
        return false;
    }
    int h_dfs(TreeNode* node) {
        if(dp.find(node) != dp.end()) return dp[node];
        dp[node] = 1 + max(h_dfs(node->left), h_dfs(node->right));
        return dp[node];
    }
};