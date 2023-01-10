class Solution {
    //https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers
    //article https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/discuss/3028076/C%2B%2B-O(NlogN)-brute-force
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