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
        |---------LT---------|-|---------RT---------|

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

        In the default, we need to search LR & RT together.
        But in our observation, we can save time to no search when some case happen
        When rv<L, don't search LT.Otherwise,search LT
        When rv>H, don't search RT.Otherwise,search RT
        rv in [L,H], rv should add into answer. 
        */

        if(!root) return 0;
        int &rv = root->val;
        int ans = 0;
        if(L<=rv && rv<=H) ans+=rv;
        ans+=rv<L?0:rangeSumBST(root->left, L,H);
        ans+=rv>H?0:rangeSumBST(root->right, L,H);
        return ans;
    }

    int rangeSumBST_refactor(TreeNode* root, int L, int H) {
        if(!root) return 0;
        int &rv = root->val;
        int ans=0;
        if(L<=rv && rv<=H) ans+=rv;
        if(rv>=L) ans+=rangeSumBST(root->left, L,H);
        if(rv<=H) ans+=rangeSumBST(root->right, L,H);
    }

    int rangeSumBST_no_optimized(TreeNode* root, int L, int H) {
        if(!root) return 0;
        int &rv = root->val;
        int ans = 0;
        if(L<=rv && rv<=H) ans+=rv;
        ans+=rangeSumBST(root->left, L,H);
        ans+=rangeSumBST(root->right, L,H);
        return ans;
    }


    int rangeSumBST_v02(TreeNode* root, int L, int H) {
        if(!root) return 0;
        int &rv = root->val;
        return (L<=rv&&rv<=H?rv:0)+(L<rv?rangeSumBST(root->left,L,H):0)+(H>rv?rangeSumBST(root->right,L,H):0);        
    }

};