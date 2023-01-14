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
    //https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree
    //article https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/discuss/3049682/C%2B%2B-One-Pass-O(N)-BFS
public:
    int maxLevelSum(TreeNode* root) {
        //BFS
        queue<TreeNode*> currQ, nextQ;
        currQ.push(root);
        int level = 1, level_sum = 0, max_level_sum=INT_MIN, ans_idx=0;
        while(!currQ.empty()) {
            TreeNode* e = currQ.front();
            level_sum+=e->val;
            currQ.pop();
            if(e->left)nextQ.push(e->left);
            if(e->right)nextQ.push(e->right);
            if(currQ.empty()) {
                if(level_sum>max_level_sum) {
                    max_level_sum = level_sum;
                    ans_idx = level;
                }
                level_sum = 0;
                level++;
                swap(currQ, nextQ);
            }
        }
        return ans_idx;
        
    }
};