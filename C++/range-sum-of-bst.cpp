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
    //https://leetcode.com/problems/range-sum-of-bst
public:
    int rangeSumBST(TreeNode* root, int L, int H) {
        /*
        LT : left tree, RT: right tree, L:low, H:high, 
        |---------LT--------|-|-------RT-------|

        case of root->val in [L,H]
        |----L----LT---------|-|---------RT----H----|
        |---------LT----L----|-|---------RT----H----|
        |----L----LT---------|-|----H----RT---------|
        |---------LT----L----|-|----H----RT---------|

        case of root->val <  [L,H]
        |---------LT---------|-|----L----RT----H----|
        |---------LT---------|-|---L-H---RT---------|
        |---------LT---------|-|---------RT---L-H---|

        case of root->val >  [L,H]
        |----L----LT----H----|-|---------RT---------|
        |---L-H---LT---------|-|---------RT---------|
        |---------LT---L-H---|-|---------RT---------|

        so rv<L, don't search LT, search RT
        so rv>H, don't search RT, search LT
        rv in [L,H], search LT+RT
        */
        if(!root) return 0;
        bool noLT=false, noRT=false;
        int &rv = root->val;
        if(rv<L) noLT =true;
        if(rv>H) noRT =true;
        int ans = 0;
        if(L<=rv && rv<=H) ans+=rv;
        if(!noLT) ans+=rangeSumBST(root->left, L,H);
        if(!noRT) ans+=rangeSumBST(root->right, L,H);
        return ans;
    }

    int rangeSumBST_v02(TreeNode* root, int L, int H) {
        if(!root) return 0;
        int &rv = root->val;
        return (L<=rv&&rv<=H?rv:0)+(L<rv?rangeSumBST(root->left,L,H):0)+(H>rv?rangeSumBST(root->right,L,H):0);        
    }

};