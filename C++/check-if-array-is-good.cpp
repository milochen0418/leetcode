class Solution {
    //https://leetcode.com/problems/check-if-array-is-good
    //article https://leetcode.com/problems/check-if-array-is-good/discuss/4144330/C%2B%2B-or-One-Pass-O(N)-simple-5-lines
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto &i:nums) 
            if(i<1||i>=n||++mp[i]>=2+(i==n-1)) return false;
        return true;
    }
};