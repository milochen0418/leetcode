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
    //https://leetcode.com/problems/average-of-levels-in-binary-tree
    //article https://leetcode.com/problems/average-of-levels-in-binary-tree/discuss/3083586/C%2B%2B-DFS-with-explanation
public:
    vector<double> averageOfLevels(TreeNode* root) {
        typedef long long ll;
        vector<vector<ll>> v; 
        function<void(TreeNode*, int)>dfs = [&](TreeNode* root, int level){
            if(!root) return;
            while(level>=v.size()) v.push_back(vector<ll>());
            v[level].push_back(root->val);
            dfs(root->left, level+1);
            dfs(root->right, level+1);
        };
        dfs(root, 0);
        
        vector<double> ans = vector<double>(v.size(),0);
        for(int i = 0;i<v.size();i++) {
            ll sum = 0;
            for(auto &l:v[i]) sum+=l;
            double avg = (double)sum/(double)(v[i].size());
            ans[i] = avg;
        }
        return ans;
    }
};