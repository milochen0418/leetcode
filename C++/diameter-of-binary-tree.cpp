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
    //https://leetcode.com/problems/diameter-of-binary-tree
    //article https://leetcode.com/problems/diameter-of-binary-tree/discuss/2328204/C%2B%2B-or-2*DFS-and-1*DFS-or-easy-understanding
public:
    int diameterOfBinaryTree(TreeNode* root) {
        //mp[node]: maximum falling path length from node to longest leave.
        //high of leave is 0; high of nullptr is -1;
        unordered_map<TreeNode*, int> high_mp;
        function<int(TreeNode*)> get_high = [&](TreeNode*root){
            if(high_mp.find(root) != high_mp.end()) return high_mp[root];
            if(root==nullptr) return high_mp[root]=-1;
            high_mp[root] = 1 + max(get_high(root->left), get_high(root->right));
            return high_mp[root];
        };
        
        unordered_map<TreeNode*, int> diameter_len_mp;
        function<int(TreeNode*)> get_diameter_len = [&](TreeNode* root) {
            if(diameter_len_mp.find(root) != diameter_len_mp.end()) return diameter_len_mp[root];
            if(!root) return diameter_len_mp[root] =0;
            diameter_len_mp[root] = 2+get_high(root->left)+get_high(root->right);
            get_diameter_len(root->left);
            get_diameter_len(root->right);
            return diameter_len_mp[root];
        };
        get_diameter_len(root);
        
        int ans = 0;
        for(auto &[node,diameter_len]: diameter_len_mp) 
            ans = max(ans, diameter_len);
        return ans;
    }

    unordered_map<TreeNode*, int> mp;//longest path from root to leaf
    int ans=0;
    int diameterOfBinaryTree_v02(TreeNode* root) {
        mp[nullptr] = 0;
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs1(root->left); 
        dfs1(root->right);
        mp[root] = 1+max(mp[root->left], mp[root->right]);
        ans = max(ans, mp[root->left] + mp[root->right]);
    }

    int diameterOfBinaryTreeVer01(TreeNode* root) {
        mp[nullptr] = 0;
        dfs1(root);
        dfs2(root);
        return ans;
    }
    void dfs1(TreeNode* root) {
        if(!root) return;
        dfs1(root->left);
        dfs1(root->right);
        mp[root] = 1+max(mp[root->left], mp[root->right]);
    }
    void dfs2(TreeNode*root) {
        if(!root) return;
        ans = max(ans, mp[root->left] + mp[root->right]);
        dfs2(root->left);
        dfs2(root->right);
    }
};