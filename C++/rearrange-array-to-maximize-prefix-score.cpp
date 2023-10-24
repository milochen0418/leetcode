class Solution {
    //https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end() ,[&](auto &lhs, auto &rhs){return lhs > rhs;});
        int ans = 0;
        long long sum = 0; 
        for(auto &i : nums) {
            sum+=(long long)i;
            if(sum <= 0)break;
            ans++;
        }
        return ans;
    }
};