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
    //https://leetcode.com/problems/smallest-string-starting-from-leaf
public:
    string smallestFromLeaf(TreeNode* root) {
        string ans;
        string tmp;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {            
            if(!root)return;
            tmp.push_back('a'+(char)root->val);
            if(!root->left && !root->right) {                
                if(ans.length()==0) {
                    ans = tmp;
                } else {
                    //get result from reversed string compare
                    int i1 = (int)ans.length(), i2=(int)tmp.length();
                    while(--i2>=0 && --i1>=0 && ans[i1]==tmp[i2]);
                    int cmp = i2<0?1:ans[i1]-tmp[i2];
                    if(cmp>0) ans=tmp;//set ans=tmp if reversed(s1)>reversed(s2)
                }
            } else {
                dfs(root->left);
                dfs(root->right);
            }
            tmp.pop_back();
        };
        dfs(root);
        reverse(ans.begin(),ans.end());
        return ans;
    }

    string smallestFromLeaf_v01(TreeNode* root) {
        string ans;
        string tmp;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {            
            if(!root)return;
            tmp.push_back('a'+(char)root->val);
            if(!root->left && !root->right) {
                reverse(tmp.begin(),tmp.end());
                if(ans=="")ans=tmp;
                else if(tmp<ans) ans = tmp;
                reverse(tmp.begin(),tmp.end());
            } else {
                dfs(root->left);
                dfs(root->right);
            }
            tmp.pop_back();
        };
        dfs(root);
        return ans;
    }
};