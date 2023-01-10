class Solution {
    //https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers
public:
    vector<int> getNoZeroIntegers(int n) {
        //O(N) number of loops
        for(int i = 1;i<n;i++) {
            int L = i, R=n-i;
            if(is_no_zero_integer(L) && is_no_zero_integer(R)) {
                return {L,R};
            }
        }
        return {0,0};
    }
    //O(logN)
    bool is_no_zero_integer(int n) {
        while(n>0){
            if(n%10==0) return false;
            n/=10;
        }
        return true;
    }
};