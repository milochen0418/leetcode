class Solution {
    //https://leetcode.com/problems/longest-harmonious-subsequence
public:
    int findLHS(vector<int>& nums) {
        vector<int>& A=nums;
        int n = A.size(), ans = INT_MIN;
        unordered_map<int,int> mp;
        for(int i = 0;i<n;i++) mp[A[i]]++;
        for(auto &[k,cnt]:mp) {
            if(mp.find(k+1)==mp.end()) continue;
            int val = cnt + mp[k+1];
            ans = max(ans, val);
        }
        return ans<0?0:ans;
    }
};