class Solution {
    //https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer
public:
    int subtractProductAndSum(int n) {
        int prod =1;
        int sum=0;
        while(n>0) {
            int i = n%10;
            sum+=i;
            prod*=i;
            n/=10;
        }
        return prod-sum;
    }
};