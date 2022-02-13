class Solution {
    //https://leetcode.com/problems/count-operations-to-obtain-zero/
public:
    int countOperations(int num1, int num2) {
        int cnt=0;
        while(!(num1 ==0 || num2 ==0) ) {
            if(num2 > num1) {
                num2 = num2 -num1;
            } else if(num1>num2){
                num1 = num1 - num2;
            } else {
                num1 = num1 - num2;
            }
            cnt++;
        }
        return cnt;
    }
};