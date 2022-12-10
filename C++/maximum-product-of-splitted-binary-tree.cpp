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
    //https://leetcode.com/problems/maximum-product-of-splitted-binary-tree
public:
    
    typedef unsigned long long valm;
    const valm mod_num = 1e9 + 7; 
    /*
    valm mod(valm a) {return a%mod_num;}
    valm mod_add(valm a, valm b) { return mod( mod(a) + mod(b) );}
    valm mod_mul(valm a, valm b) { return mod( mod(a) * mod(b) );}
    valm mod_sub(valm a, valm b) { 
        valm v=mod( mod(a) - mod(b) );
        return v<0?v+mod_num:v;
    }
    */

    /* if you use unsigned long long to figure out solution in this problem, that's enough for all caculation
    But the only problem is that the problem request you to return int.  
    */
    
    valm mod(valm a) {return a%mod_num;}
    /*
    valm mod_add(valm a, valm b) { return a+b;}
    valm mod_mul(valm a, valm b) { return mod( mod(a) * mod(b) );}
    valm mod_sub(valm a, valm b) { 
        return a-b;
    }
    */
    
    unordered_map<TreeNode*,valm> mp;
    int maxProduct(TreeNode* root) {
        valm total = sum_dfs(root);
        
        //valm ans = (valm)INT_MIN;
        valm ans = (valm)0;
        for(auto &[node, sum]: mp) {
            //valm total_sum = mod_sub(total, sum);
            //valm prod = mod_mul(sum, total_sum);
            ans = max(ans, sum* (total-sum));
            //ans = max(ans, sum*(total-sum));
            //printf("prod = %ld ,ans = %ld, max() = %ld\n", prod, ans, max(ans,prod));
        }
        return (int)(mod(ans)) ;
        //return ans;
    }
    valm sum_dfs(TreeNode *root){
        if(!root) return 0;
        //mp[root] = mod_add(sum_dfs(root->left), sum_dfs(root->right));
        //mp[root] = mod_add(sum_dfs(root->left), sum_dfs(root->right));
        //mp[root] = mod_add(mp[root], root->val);
        mp[root] = root->val + sum_dfs(root->left) + sum_dfs(root->right);
        return mp[root];
    } 
};