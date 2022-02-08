class Solution {
    //https://leetcode.com/problems/add-digits
public:
    int addDigits(int num) {
        while(true) {
            int sum = 0;
            while(num>0) { //111/10=11. 11/10=1. 
                sum+=(num%10);
                num/=10;
            }
            if(sum<10) {
                return sum;
            } else {
                num = sum;
            }
        }
        return 1;
    }
};