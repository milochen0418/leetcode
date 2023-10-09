class Solution {
    //https://leetcode.com/problems/pass-the-pillow
public:
    int passThePillow(int n, int time) {
        //(n-1)*2 time will go back to original idx 1
        time %= (2*(n-1));
        if(time<n) 
            return 1+time;
        else
            return n-(time-(n-1));
    }
};