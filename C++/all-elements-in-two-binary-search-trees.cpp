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
    //https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
    /*
    Test case pass
    [2,1,4]
    [1,0,3]
    Test case failed
    [0,null,59,57,90]
    [60,17,74,6,20,63,97,null,null,null,null,null,null,95]
    */

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;        
        if(root1 != nullptr) s1.push(root1);
        if(root2 != nullptr) s2.push(root2);
        while( !(s1.empty() && s2.empty()) ) {
            int s1topval = s1.empty()?INT_MAX:s1.top()->val;
            int s2topval = s2.empty()?INT_MAX:s2.top()->val;
            
            stack<TreeNode*>*ps  = s1topval < s2topval? &s1: &s2;
            TreeNode* e = ps->top();
            
            if(e->left != nullptr && e->left->val != INT_MIN) {
                ps->push(e->left);
            } else {
                v.push_back(e->val);
                e->val = INT_MIN;
                ps->pop();
                if(e->right != nullptr && e->right->val != INT_MIN) {
                    ps->push(e->right);
                }
            }
        }
        return v;
    }
};