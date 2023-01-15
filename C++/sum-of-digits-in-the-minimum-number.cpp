class Solution {
    //https://leetcode.com/problems/sum-of-digits-in-the-minimum-number
public:
    int sumOfDigits(vector<int>& nums) {
        int minv = INT_MAX;
        for(auto &i:nums) minv = min(minv,i);
        int dsum = 0;
        while(minv>0) {
            dsum += minv%10;
            minv/=10;
        }
        if(dsum % 2 == 1) return 0;
        return 1;
    }
};