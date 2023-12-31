class Solution {
    //https://leetcode.com/problems/check-if-bitwise-or-has-trailing-zeros
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int evencnt = 0;
        for(auto &i: nums) {
            evencnt+=(i%2==0);
            if(evencnt>=2) return true;
        }
        return false;
    }
};