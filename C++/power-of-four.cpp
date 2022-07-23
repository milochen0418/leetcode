class Solution {
    //https://leetcode.com/problems/power-of-four
public:
    bool isPowerOfFour(int n) {
        if(n<0) return false;
        int one_cnt = 0;
        int zero_cnt = 0;
        for(int i = 1; i<32;i+=2) {
            if( ((1<<i)&n) >0 ) {
                return false;
            }
        }

        for(int i = 0; i<32;i+=2) {
            if( ((1<<i) & n) > 0) one_cnt++; 
        }

        return one_cnt==1;
    }
};