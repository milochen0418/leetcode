class Solution {
    //https://leetcode.com/problems/count-complete-subarrays-in-an-array
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans = 0, n = nums.size();
        unordered_set<int> set;
        for(auto &i:nums) set.insert(i);
        for(int i = 0 ;i <n; i++) {
            unordered_set<int> s;
            for(int j = i;j<n;j++) {
                s.insert(nums[j]);
                if(s.size() == set.size()) ans++;
            }            
        }
        return ans;
    }
};