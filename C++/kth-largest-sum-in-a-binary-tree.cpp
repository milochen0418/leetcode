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
    //https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree
    //article https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/discuss/4353653/C%2B%2B-use-min-queue-%2B-BFS
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        typedef long long ll;
        priority_queue<ll,vector<ll>, greater<ll>> minQ;
        queue<TreeNode*> currQ, nextQ;
        currQ.push(root);
        ll levelsum = 0;
        while(!currQ.empty()){
            TreeNode* node=currQ.front();
            levelsum+=node->val;
            currQ.pop();
            if(node->left) nextQ.push(node->left);
            if(node->right)nextQ.push(node->right);
            if(currQ.empty()) {
                minQ.push(levelsum);
                if(minQ.size()>k) minQ.pop();
                levelsum = 0;
                swap(currQ,nextQ);
            }
        }
        if(minQ.size()<k) return -1;
        return minQ.top();
        
    }
};