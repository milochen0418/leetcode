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
    //article https://leetcode.com/problems/create-binary-tree-from-descriptions/discuss/1851235/C%2B%2B-or-O(n)-or-unordered_map-or-explain
    //https://leetcode.com/problems/create-binary-tree-from-descriptions/
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, int> parents_mp; 
        for(auto& desc: descriptions) { 
            if(mp[desc[0]] == nullptr) {
                mp[desc[0]] = new TreeNode(desc[0]);
            }
            if(mp[desc[1]] == nullptr) {
                mp[desc[1]] = new TreeNode(desc[1]);
            }
            
            if(desc[2]==1) {
                mp[desc[0]]->left = mp[desc[1]];
            } else {
                mp[desc[0]]->right = mp[desc[1]];
            }
            parents_mp[desc[1]] = desc[0];
        }
        int child = descriptions[0][1];        
        while(parents_mp.find(child) != parents_mp.end()) child = parents_mp[child];
        return mp[child];
    }
};