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
    //https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree
public:
    unordered_map<TreeNode*, vector<int>> mp; //mp[node with val 5] = {2,0}
    unordered_map<int, vector<vector<int>> > mmp; 
    //mp[col][0] = vector of all row=0,col. sortint it 
    //mp[col][1] = vector of all row=1,col. sorting it
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs1(root,0,0);
        int col_min = 0, col_max=0;
        for(auto &[k,rc]: mp) {
            col_min = min(col_min, rc[1]);
            col_max = max(col_max, rc[1]);
        }

        dfs2(root);
        for(auto &[col, cv]: mmp) 
            for(auto &v: cv) 
                sort(v.begin(),v.end());
        
        vector<vector<int>> ans;
        for(int col = col_min; col<=col_max;col++) {
            vector<vector<int>> cv = mmp[col];
            vector<int> v;
            for(auto &v1:cv) 
                for(auto &val:v1) 
                    v.push_back(val);
            ans.push_back(v);
        }
        return ans;
    }
    
    void dfs1(TreeNode* root, int row, int col) {
        if(!root) return;
        mp[root] = {row, col};
        dfs1( root->left, row+1, col-1);
        dfs1(root->right, row+1, col+1);
    }
    void dfs2(TreeNode* root) {
        if(!root) return;
        vector<int> rc = mp[root];
        int row = rc[0], col = rc[1];
        while(row>=mmp[col].size())mmp[col].push_back(vector<int>());
        mmp[col][row].push_back(root->val);
        dfs2(root->left);
        dfs2(root->right);
    }
};