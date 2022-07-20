class Solution {
    //https://leetcode.com/problems/add-binary
public:
    string addBinary(string a, string b) {
        string ans="";
        int m = a.length(), n = b.length(), end = max(m,n);
        int bit_c = 0;
        for(int i = 0; i<end;i++) {
            int bit_a = m-i-1>=0?a[m-i-1]-'0':0;
            int bit_b = n-i-1>=0?b[n-i-1]-'0':0;
            int sum = bit_a+bit_b+bit_c;
            bit_c = sum/2;
            sum = sum%2;
            ans.push_back(sum+'0');
        }
        if(bit_c>0)ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};