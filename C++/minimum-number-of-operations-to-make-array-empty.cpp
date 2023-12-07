class Solution {
    //https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(auto &v:nums) mp[v]++;
        for(auto& [k,v]:mp) {
            if(v==1) return -1;
            if(v%3==0) ans+=v/3;
            if(v%3==2) ans+=(v+1)/3;
            if(v%3==1) ans+=(v+2)/3;
        }
        return ans;     
    }
};