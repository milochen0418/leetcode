class Solution {
    //https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty
    //article https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/discuss/4375285/C%2B%2B-simple-9-lines-O(N)-with-explain
public:

    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;
        vector<int> r={0,2,1};
        for(auto &v:nums) mp[v]++; //[0]=0, [1]=2, [2]=1
        for(auto& [k,v]:mp) {
            if(v==1) return -1;
            ans+=(v+r[v%3])/3;
        }
        return ans;     
    }

    int minOperations_v01(vector<int>& nums) {
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