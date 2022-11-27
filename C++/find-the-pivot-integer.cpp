class Solution {
    //https://leetcode.com/problems/find-the-pivot-integer/
public:
    int pivotInteger(int n) {
        //1+2+3 = (3+1)*3 / 2   1+...+n 
        int total = ((n+1)*n)/2;
        for(int i = 1; i<=n;i++) {
            int m = ((i+1)*i)/2;
            if( (total - m + i) == m) return i;
        }
        return -1;
    }
};