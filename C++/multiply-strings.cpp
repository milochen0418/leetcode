class Solution {
    //https://leetcode.com/problems/multiply-strings
    //article https://leetcode.com/problems/multiply-strings/discuss/3033785/C%2B%2B-Simulation
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        string ans="0";
        int n=num1.length();
        
        for(int i=0;i<n;i++){
            string s = mul(num1[i], num2);
            if(i>0) s = string(i,'0').append(s);
            ans = add(ans, s);
        }
        //string ans = add(num1, num2); put same number to test
        //string ans = mul('9',num2); put input data "9","39" to test
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string mul(char val, string num) {
        string ans;
        int carry = 0, n = num.length();
        for(int i = 0;i<n;i++) {
            int v = (num[i]-'0');
            int mul = (val-'0')*v + carry;
            carry = mul/10;
            ans.push_back( (mul%10)+'0');
        }
        if(carry>0) ans.push_back(carry+'0');
        return ans;
    }
    string add(string num1, string num2) {
        string ans;
        int n = max((int)num1.length(), (int)num2.length());
        int carry = 0;
        for(int i = 0; i<n; i++) {
            int v1 = (i<num1.length())?num1[i]-'0':0;
            int v2 = (i<num2.length())?num2[i]-'0':0;
            int sum = v1+v2+carry;
            //printf("i=%d, sum=%d\n", i,sum);
            carry = sum/10;
            ans.push_back(sum%10+'0');
        }
        if(carry != 0) ans.push_back(carry%10+'0');
        return ans;
    }
};