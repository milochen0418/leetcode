class Solution {
    //https://leetcode.com/problems/alternating-digit-sum/
    //article https://leetcode.com/problems/alternating-digit-sum/discuss/3085117/C%2B%2B-One-Pass-O(logN)-8-lines
public:
    int alternateDigitSum(int n) {
        int cnt=0;
        int sign = 1;
        int sum = 0;
        while(n>0) {
            int d = n%10;
            sum += sign*d;
            sign*=-1;
            cnt++;
            n/=10;
        }
        if(cnt%2==0) sum*=-1;
        return sum;
    }
};