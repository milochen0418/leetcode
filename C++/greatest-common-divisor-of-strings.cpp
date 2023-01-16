class Solution {
    //https://leetcode.com/problems/greatest-common-divisor-of-strings
    
public:
    string gcdOfStrings(string str1, string str2) {
        //Refer solution to find to math rule
        if(str1+str2 != str2+str1) return "";
        return str1.substr(0,gcd(str1.length(), str2.length()));
    }
};