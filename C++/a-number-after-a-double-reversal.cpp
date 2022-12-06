class Solution {
    //https://leetcode.com/problems/a-number-after-a-double-reversal
public:
    bool isSameAfterReversals(int num) {
        if(num==0) return true;
        string s = to_string(num);
        if(s[0]=='0' || s[s.length()-1]=='0') return false;
        return true;
    }
};