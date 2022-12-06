class Solution {
    //https://leetcode.com/problems/find-greatest-common-divisor-of-array
public:
    int findGCD(vector<int>& nums) {
        int minv=INT_MAX, maxv=INT_MIN;
        for(auto &i:nums) {
            minv = min(i,minv);
            maxv = max(i,maxv);
        }
        return gcd(minv,maxv);
    }
};