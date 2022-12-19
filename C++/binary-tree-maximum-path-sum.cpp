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
    //https://leetcode.com/problems/binary-tree-maximum-path-sum
    //article https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/2928712/C%2B%2B-or-easy-DFS-O(N)-maximum-falling-path-or-explanation
public:
    unordered_map<TreeNode*, int> mp;
    int ans=INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs1(root);
        dfs2(root);
        return ans;
    }
    
    int dfs1(TreeNode* root) { //DFS1 to find out all maximum falling path 
        if(mp.find(root) == mp.end()) {
            if(!root) 
                mp[root]=0;
            else {
                int L = dfs1(root->left);
                int R = dfs1(root->right);
                int maxLR = max(0,max(L,R));
                int maxfalling = max(0, root->val + maxLR);
                mp[root] = maxfalling;
            }
        }
        return mp[root];
    }
    void dfs2(TreeNode* root) {//DFS2 to find out who have maximum path sum
        if(!root) return;
        int val = root->val + mp[root->left] + mp[root->right];
        ans = max(ans, val);
        dfs2(root->left);
        dfs2(root->right);
    }  
};