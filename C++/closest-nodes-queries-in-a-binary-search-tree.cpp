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
    //https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        for(auto &q: queries) {
            ans.push_back(sol(root, q));
        }
        return ans;
    }
    vector<int> sol(TreeNode* root, int q) {
        vector<int> ret;
        ret.push_back(find_min(root, q));
        ret.push_back(find_max(root, q));
        return ret;
    }
    
    // find the min which is the largest value smaller or equal than q 
    int find_min(TreeNode* root, int q) { 
        int c = -1; // candidate
        while(root != nullptr) {
            int v = root->val;
            if(v == q) {
                return q;
            } else if(v < q) {
                c = v;
                root = root->right;
            } else { //if(v > q)
                root = root->left;
            }
        }
        return c;
    }
    // find the max which is the smallest value larger or equal than q 
    int find_max(TreeNode* root, int q) {
        int c = -1; // candidate
        while(root != nullptr) {
            int v = root->val;
            if(v == q) {
                return q;
            } else if(v > q) {
                c = v;
                root = root->left;
            } else { //if(v > q)
                root = root->right;
            }
        }
        return c;

    }
    
};