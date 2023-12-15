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
    //https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree
public:
    int pseudoPalindromicPaths (TreeNode* root) {

        unordered_map<int,int> mp; //trace map for counting of node's value in path
        int ans = 0;
        function<void(TreeNode*)> dfs = [&](TreeNode* root){
            mp[root->val]++;
            if( (!root->left) && (!root->right)) {
                int even=0, odd=0;
                for(auto &[k,v]:mp) {
                    if(v%2==0)even++;
                    if(v%2==1)odd++;
                }
                if(odd<=1) ans++;
            } else {
                if(root->left) dfs(root->left);
                if(root->right) dfs(root->right);
            }
            mp[root->val]--;
        };
        dfs(root);
        return ans;
    }
};