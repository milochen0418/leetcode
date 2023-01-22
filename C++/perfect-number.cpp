class Solution {
    //https://leetcode.com/problems/perfect-number
public:
    bool checkPerfectNumber(int num) {
        //O(sqrt(N))
        int sum = 0;
        for(int i =1; i*i<=num;i++) 
            if(num%i==0) {
                sum+=i;
                if(i*i!=num) {
                    sum+=num/i;
                }
            }
        return sum-num==num;
    }    
    bool checkPerfectNumber_v02(int num) {
        //O(N)
        int sum = 0;
        for(int i =1; i<=num/2;i++) 
            if(num%i==0) sum+=i;
        return sum==num;
    }
};