class Solution {
    //https://leetcode.com/problems/calculate-digit-sum-of-a-string
public:
    string digitSum(string s, int k) {
        while(s.length()>k) {
            string m;
            int base = 0;
            while(base<s.length()) {
                int val=0;
                for(int i = base;i<min( base+k,(int)s.length());i++) val+=(s[i]-'0');
                m = m + to_string(val);
                base = base + k;
            }
            s=m;            
        }
        return s;
    }
};