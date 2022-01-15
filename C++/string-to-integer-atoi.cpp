class Solution {
    //https://leetcode.com/problems/string-to-integer-atoi/
public:
    int myAtoi(string str) {
        const char* s = str.c_str();
        long result = 0;
        int i = 0; 
        while(s[i] == ' ') i++;
        int sign = 1;
        if(s[i] == '-') {
            sign = -1;
            i++;
        } else if(s[i] == '+') {
            sign = 1;
            i++;
        }
        
        while(s[i] >= '0' && s[i] <= '9') {
            result = result * 10 + sign*(s[i] - '0');
            if(sign == -1 && result < INT_MIN) {
                return INT_MIN;
            } 
            if(sign == 1 && result > INT_MAX) {
                return INT_MAX;
            }
            i++;
        }
        
        return (int)result;
        
    }
};