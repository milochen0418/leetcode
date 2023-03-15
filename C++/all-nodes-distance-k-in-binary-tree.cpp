/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    //https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree
    //article https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/discuss/3298489/C%2B%2B-or-DFS-%2B-BFS
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0) return {target->val};
        unordered_map<int,vector<int>> mp;//edges   
        function<void(TreeNode*)> dfs_build_edges = [&](TreeNode* root) {
            for(auto &child: {root->left, root->right}) if(child) {
                mp[root->val].push_back(child->val);
                mp[child->val].push_back(root->val);
                dfs_build_edges(child);
            }
        };
        dfs_build_edges(root);//build bi-direction tree graph
        
        //Use BFS to search distance k node from target by the above built graph
        unordered_set<int> visited;
        vector<int>ans;
        queue<int> currQ,nextQ;
        visited.insert(target->val);
        currQ.push(target->val);
        while(!currQ.empty()) {
            int e = currQ.front();currQ.pop();
            for(auto& node:mp[e]) {
                if(visited.find(node) == visited.end()) {
                    visited.insert(node);
                    nextQ.push(node);
                }
            }
            if(currQ.empty()) {
                k--;
                if(k==0) {
                    while(!nextQ.empty()) {
                        ans.push_back(nextQ.front());
                        nextQ.pop();
                    }
                    break;
                } else {
                    swap(currQ,nextQ);
                }
            }
        }
        return ans;
    }
};