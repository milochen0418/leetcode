class Solution {
    //https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        int maxv = -1;
        for(auto &i:nums) maxv = max(maxv, i);
        
        vector<int> mp = vector<int>(maxv,0);
        for(auto &i:nums) mp[i]++;
        vector<int> cnt = vector<int>(maxv,0);
        cnt[0] = 0;
        for(int i = 1;i<maxv;i++) {
            cnt[i] = cnt[i-1]+mp[i];
        }
        
        return cnt;
        
    }
};