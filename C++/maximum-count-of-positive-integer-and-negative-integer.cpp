class Solution {
    //https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        for(auto &i: nums) {
            if(i<0) neg++;
            if(i>0) pos++;
        }
        return max(neg,pos);
    }
};