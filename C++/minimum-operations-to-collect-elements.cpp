class Solution {
    //https://leetcode.com/problems/minimum-operations-to-collect-elements
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s;
        int n = nums.size(), ans = 0;
        for(int i = n-1;i>=0;i--) {
            ans++;
            if(nums[i]<=k) s.insert(nums[i]);
            if(s.size() == k) return ans;
        }
        return ans;
    }
};