class Solution {
    //https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum
public:
    int minStartValue(vector<int>& nums) {
        int minv = INT_MAX, v=0;
        for(auto &i: nums) {
            v+=i;
            minv = min(minv, v);
        }
        return max(1,1-1*minv);
    }
};