class Solution {
    //https://leetcode.com/problems/convert-a-number-to-hexadecimal
public:
    const vector<char> hv={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    string toHex(int num) {
        string ans=string(8,'0');
        long long val = num;
        long long sign = 1;
        if(val<0) {
            sign=-1;
            val = val*-1;
        }
        vector<int> hex_digits =  vector<int>(8,0);
        if(sign == 1) {
            for(int i=7;i>=0;i--) {
                hex_digits[i] = val%16;
                val/=16;
            }
            return hexd_to_str(hex_digits);
        } 
        
        //case of sign == -1
        //The way to find out 2's complement for negative value
        //is get complement of positive value part and then add one.
        //1. get complement
        for(int i=7;i>=0;i--) {
            hex_digits[i] = 15-(val%16);
            val/=16;
        }
        //2. add one for complement
        for(int i=7;i>=0;i--) {
            hex_digits[i]+=1;
            if(hex_digits[i]<16) break;
            hex_digits[i]=0;
        }
        

        return hexd_to_str(hex_digits);
        
    }
    string hexd_to_str(vector<int>& hex_digits) {
        //return string according to the requriement of this problem
        //26 -> "0000001a" -> "1a"
        //0  -> "00000000" -> "0"
        int n = hex_digits.size(),j=0;
        string s = string(n,'0'), ans;
        for(int i = 0; i<n;i++) s[i] = hv[hex_digits[i]];
        while(s[j]=='0') j++;
        if(j>=n) return "0";
        for(int i=j;i<n;i++) ans.push_back(s[i]);        
        return ans;
    }
};