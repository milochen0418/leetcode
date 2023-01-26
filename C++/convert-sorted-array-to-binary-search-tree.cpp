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
    //https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
    //article https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/discuss/3099915/C%2B%2B-DFS-O(N)-6-lines
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        function<TreeNode*(int,int)> dfs=[&](int L,int R) {
            if(L>R) return (TreeNode*)nullptr;
            int M = L + (R-L)/2;
            return new TreeNode(nums[M],dfs(L,M-1), dfs(M+1,R));
        };        
        return dfs(0,nums.size()-1);
    }

    TreeNode* sortedArrayToBST_v01(vector<int>& nums) {
        return dfs(nums,0,nums.size()-1);
    }
    TreeNode* dfs(vector<int>& A,int L, int R) {
        int M = L+(R-L)/2;
        return L>R?nullptr:new TreeNode(A[M], dfs(A,L,M-1), dfs(A,M+1,R));
    }
};