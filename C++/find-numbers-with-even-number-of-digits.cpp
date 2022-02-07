class Solution {
    //https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(auto num: nums) {
            int digit_num = 0;
            while(num>0) {
                num/=10;
                digit_num+=1;
            }
            if(digit_num % 2 == 0) cnt++;
        }
        return cnt;
    }
};