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
    //https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/
public:
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> currQ, nextQ;
        currQ.push(root);
        
        vector<int> v;
        while(!currQ.empty()) {
            TreeNode* e = currQ.front();
            currQ.pop();
            if(e->left != nullptr) {
                v.push_back(e->left->val);
                nextQ.push(e->left);
            }
            if(e->right != nullptr) {
                v.push_back(e->right->val);
                nextQ.push(e->right);
            }
            if(currQ.empty()) {
                ans += minSwaps(v);
                v.clear();
                swap(nextQ, currQ);
            }
        }
        return ans;
    }
    
    int minSwaps(vector<int>& arr) {
        //refer https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
        int n = arr.size();
        vector<pair<int,int>> arrPos = vector<pair<int,int>>(n);
        for (int i = 0; i < n; i++) {
            arrPos[i].first = arr[i];
            arrPos[i].second = i;
        }

        sort(arrPos.begin(), arrPos.end());
        vector<bool> vis(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] || arrPos[i].second == i) continue;
            int cycle_size = 0;
            int j = i;
            while (!vis[j]) {
                vis[j] = 1;
                j = arrPos[j].second;
                cycle_size++;
            }
            if (cycle_size > 0) ans += (cycle_size - 1);
        }
        return ans;
    }
     
};