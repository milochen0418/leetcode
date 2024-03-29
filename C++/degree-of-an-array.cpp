class Solution {
    //https://leetcode.com/problems/degree-of-an-array/
    //article https://leetcode.com/problems/degree-of-an-array/discuss/3077894/C%2B%2B-Two-Pass-O(N)-10-lines
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int max_freq = 0,ans=INT_MAX;
        for(int i = 0; i<nums.size();i++) {
            mp[nums[i]].push_back(i);
            max_freq=max(max_freq,(int)mp[nums[i]].size());
        }
        for(auto &[k,v]:mp) 
            if(v.size() == max_freq) 
                ans = min(v.back() - v.front() + 1,ans);
        return ans;
    }
};