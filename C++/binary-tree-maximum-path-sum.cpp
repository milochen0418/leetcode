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
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        dfs(root);
        for(auto &[root,v]:mp) {
            if(!root) continue;
            int val = root->val + mp[root->left] + mp[root->right];
            ans = max(ans, val);
        }
        return ans;
    }
    
    int dfs(TreeNode* root) { //DFS to find out all maximum falling path 
        if(mp.find(root) == mp.end()) {
            if(!root) 
                mp[root]=0;
            else {
                int L = dfs(root->left);
                int R = dfs(root->right);
                //mp[root] = root->val + max(L,R);
                int maxLR = max(0,max(L,R));
                int max_falling = max(0, root->val + maxLR);
                mp[root] = max_falling;
            }
        }
        return mp[root];
    }    
};