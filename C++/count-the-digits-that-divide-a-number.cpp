class Solution {
    //https://leetcode.com/problems/count-the-digits-that-divide-a-number/
public:
    int countDigits(int num) {
        int ans = 0;
        int n = num;
        while(num>0) {
            int r = num% 10;
            num /= 10;
            if(r!=0 && n%r==0) ans++;
        }
        return ans;
    }
};