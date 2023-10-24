class Solution {
    //https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score
    //article https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/discuss/4203831/C%2B%2B-simple-9-lines-by-sort
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