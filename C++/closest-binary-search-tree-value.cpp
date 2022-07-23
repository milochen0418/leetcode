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
    //https://leetcode.com/problems/closest-binary-search-tree-value/
public:
    vector<int> a;
    int closestValue(TreeNode* root, double target) {
        /*
         Observation : 
             idea : sorting order of binary search tree 
             e.g., 1,2,3,4,5   with target 3.714286
             
             Sorting order: traversal in style like Left, Parent, Right
             
             //Edge Caes? there is not nullptr root. 
             
        */
        dfs(root);
        //right now a is sorting order that start from smallest. 
        
        //idea 2, use binary search to find cloest element 
        //the smallest size of a is 1. 
        int lval = INT_MIN;
        int rval = INT_MAX;
        //(1)Find the largest number `lval` in a that smaller or equal than target
        int n = a.size(), L=0, R=n-1;
        while(L<=R) {
            int M = L + (R-L)/2; //(L+R)/2
            if( (M+1>=n || a[M+1] > target) && a[M] <= target) {//match case
                lval = a[M];
            }
            //search in left-side or right-side
            if(a[M]<=target) { //a[M+1] also <=target. M is stay in left side of searching answer
                L=M+1; //go to search right side 
            } else {
                R=M-1; //go to search left side
            }
            
        }
        
        
        //(2)Find the smallest number `rval` in a that greater or equal than target. 
        L=0;
        R=n-1;
        while(L<=R) {
            int M = L + (R-L)/2; //(L+R)/2
            if( (M-1<0 || a[M-1] < target) && a[M] >= target) {//match case
                rval = a[M];
            }
            
            if(a[M] >= target) { //a[M-1] also >= target. M is stay in right side of searching answer
                R=M-1; //go to search left side
            } else {
                L=M+1; //go to search right side
            }
            
        }
        
        if(abs(double(lval-target)) < abs(double(rval-target))) {
            return lval;
        } else {
            return rval;
        }
        
    }
    void dfs(TreeNode* root) {
        if(root==nullptr) return;
        dfs(root->left);
        a.push_back(root->val);
        dfs(root->right);
    }
};