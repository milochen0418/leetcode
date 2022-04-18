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
    //https://leetcode.com/problems/kth-smallest-element-in-a-bst
public:
    priority_queue<int> maxQ; 
    int size_k = 0;
    int kthSmallest(TreeNode* root, int k) {
        size_k = k;
        travelBST(root);
        return maxQ.top();
    }
    
    void travelBST(TreeNode* root) {
        if(root == nullptr) return;    
        travelBST(root->left);
        maxQ.push(root->val);
        if (maxQ.size()>size_k) {
           maxQ.pop(); 
        }
        travelBST(root->right);
    }
};