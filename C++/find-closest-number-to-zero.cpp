class Solution {
    //https://leetcode.com/problems/find-closest-number-to-zero/
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = INT_MAX;
        int sign = 1;
        for(auto &i:nums) {
            if(abs(i)<ans) {
                sign = (i>0)*2-1;
                ans = abs(i);
            } else if (abs(i) == ans) {
                if((i>0)*2-1 > sign) {
                    sign = 1;
                    ans = abs(i);
                }
            }
        }
        ans *= sign;
        return ans;
    }
};