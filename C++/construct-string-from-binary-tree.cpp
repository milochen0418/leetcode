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
    //https://leetcode.com/problems/construct-string-from-binary-tree/
    //article https://leetcode.com/problems/construct-string-from-binary-tree/discuss/3103726/C%2B%2B-DFS
public:
    string tree2str(TreeNode* root) {
        string ans;
        function<void(TreeNode*)> dfs = [&](TreeNode*root){
            if(!root) return ;
            ans.append(to_string(root->val));
            if(!root->left && !root->right) return;
            ans.push_back('(');
            dfs(root->left);
            ans.push_back(')');
            
            if(root->right) {
                ans.push_back('(');
                dfs(root->right);
                ans.push_back(')');
            }            
        };
        dfs(root);
        return ans;
    }
};