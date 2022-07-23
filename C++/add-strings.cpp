class Solution {
    //https://leetcode.com/problems/add-strings/
public:
    string addStrings(string num1, string num2) {
        string ans="";        
        int carry = 0;
        int sum = 0;
        int n = max(num1.length(), num2.length());
        for(int k = 0; k < n+1;k++) {
            int i = num1.length()-1-k;
            int j = num2.length()-1-k;
            int a = i<0? 0: (num1[i]-'0');
            int b = j<0? 0: (num2[j]-'0');
            sum = a + b + carry;
            carry = sum>=10?1:0;
            sum%=10;
            if(sum==0 && carry==0 && k>=n-1) break;
            ans.push_back(sum+'0');
        }
        reverse(ans.begin(), ans.end());
        if(ans=="")ans="0";
        return ans;
    }
};