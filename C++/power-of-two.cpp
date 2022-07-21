class Solution {
    //https://leetcode.com/problems/power-of-two
public:
    bool isPowerOfTwo(int n) { 
        if(n<=0)return false;
        int cnt=0;
        for(int i = 0;i<32;i++) if( (1<<i)&n ) cnt++;
        return cnt==1;
    }
};