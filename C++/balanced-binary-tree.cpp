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
    //https://leetcode.com/problems/balanced-binary-tree
    //article https://leetcode.com/problems/balanced-binary-tree/discuss/2311350/C%2B%2B-or-Improve-from-2-DFS-into-1-DFS
public:


    bool isBalanced(TreeNode* root) {
        unordered_map<TreeNode*, int> high;
        function<int(TreeNode*)> get_high = [&](TreeNode*root){
            if(high.find(root) != high.end()) return high[root];
            if(!root) return high[root]=0;
            int lh = get_high(root->left);
            int rh = get_high(root->right);
            high[root] = 1+max(lh,rh);
            return high[root];
        };
        get_high(root); //call dfs
        
        function<bool(TreeNode*)> balance = [&](TreeNode*root){
            if(!root) return true;
            if(balance(root->left)==true && balance(root->right)==true) 
                if(abs(high[root->left]-high[root->right])<= 1) 
                    return true;
            return false;
        };
        return balance(root);
    }

    unordered_map<TreeNode*, int> mp;    
    bool isBalanced_v02(TreeNode* root) {
        if(!root) return true;
        if(isBalanced(root->left) && isBalanced(root->right)) {
            if(abs(get_height(root->left)-get_height(root->right))<=1) {
                return true;
        return false;
    }
    
    //DP DFS
    int get_height(TreeNode* root) {
        if(!root) return 0;
        if(mp.find(root) != mp.end()) return mp[root];
        int hl = get_height(root->left);
        int hr = get_height(root->right);
        int high =1+max(hl,hr);
        mp[root] = high;
        return mp[root];
    }

    unordered_map<TreeNode*, int> dp;//height of TreeNode
    bool isBalanced_v01(TreeNode* root) {
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