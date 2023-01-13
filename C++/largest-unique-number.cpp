class Solution {
    //https://leetcode.com/problems/largest-unique-number
public:
    unordered_map<int,int> mp;
    int largestUniqueNumber(vector<int>& nums) {
        int maxv = -1;
        for(auto &i:nums) mp[i]++;
        for(auto &[k,v]: mp) { 
            if(mp[k] == 1) {
                maxv = max(k,maxv);
            } 
        }
        return maxv;
    }
};