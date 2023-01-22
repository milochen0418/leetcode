class Solution {
    //https://leetcode.com/problems/base-7
public:
    string convertToBase7(int num) {
        
        if(num==0)return "0";
        string ans;
        int sign = abs(num)/num;
        
        num*=sign;
        while(num>0) {
            ans.push_back((num%7)+'0');
            num/=7;
        }
        if(sign < 0) ans.push_back('-');
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};