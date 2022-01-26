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
    //Refer this answer ?https://leetcode.com/problems/all-elements-in-two-binary-search-trees/discuss/1721722/c%2B%2Bor-iterative-or-using-stack
    /*
    Test case pass
    [2,1,4]
    [1,0,3]
    Test case pass
    [0,null,59,57,90]
    [60,17,74,6,20,63,97,null,null,null,null,null,null,95]
    Test case failed
    [99,90,null,8,null,7,85,null,null,null,87]
    [50,2,73,null,34,58,80,21,null,null,64,74,92,10,null,null,68,null,null,89,100,null,null,66,null,84]
    */

   /*
                                 [99,
                    90,                       null,
            8,            null,        
       7,      85, 
  null null  null 87


[                   50,
       2,                           73,
null,       34,          58,                     80,
          21,null,     null, 64,           74,         92,
        10,null,          null,   68,   null,null,   89, 100,   
    null,null,                  66,null,           84]
   */

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2; 
        
        if(root1 != nullptr) {
            s1.push(root1);
            TreeNode*e = root1;
            while(e->left != nullptr && e->left->val != INT_MIN) {
                s1.push(e->left);
                e = e->left;
            }
        }
        if(root2 != nullptr) {
            s2.push(root2);
            TreeNode*e = root2;
            while(e->left != nullptr && e->left->val != INT_MIN) {
                s2.push(e->left);
                e = e->left;
            }
        }

        while( !(s1.empty() && s2.empty()) ) {
            int s1topval = s1.empty()?INT_MAX:s1.top()->val;
            int s2topval = s2.empty()?INT_MAX:s2.top()->val;
            
            stack<TreeNode*>*ps  = s1topval < s2topval? &s1: &s2;
            TreeNode* e = ps->top();
            
            while(e->left != nullptr && e->left->val != INT_MIN) {
                ps->push(e->left);
                e=e->left;
            }
            
            v.push_back(e->val);
            e->val = INT_MIN;
            ps->pop();
            if(e->right != nullptr && e->right->val != INT_MIN) {
                ps->push(e->right);
            }
        }
        return v;
    }   
};