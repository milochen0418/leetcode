class Solution {
    //https://leetcode.com/problems/number-of-distinct-averages
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), L=0, R=n-1;
        unordered_set<int> s;
        while(L<R) s.insert(nums[L++] + nums[R--]);
        return s.size();
    }
};