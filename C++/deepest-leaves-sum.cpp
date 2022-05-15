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
    //https://leetcode.com/problems/deepest-leaves-sum/
    //Article https://leetcode.com/problems/deepest-leaves-sum/discuss/2042478/C%2B%2B-or-BFS-or-Explanation
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> curQ, nextQ;
        curQ.push(root);
        int sum = 0;
        while(!curQ.empty()) {
            TreeNode* e = curQ.front();
            sum+=e->val;
            curQ.pop();
            for(auto &c: {e->left, e->right}) 
                if(c!=nullptr) 
                    nextQ.push(c);
            if(curQ.empty()) {
                swap(curQ,nextQ);
                if(!curQ.empty())sum=0;
            }
        }
        return sum;
    }
};