class Solution {
    
    /*     O X   X O  
    0 0 -> 0 0   0 0
    0 1 -> 1 1   1 1
    1 0 -> 1 1   1 1
    1 1 -> 1 0   0 1
    
    11 can decide some bit to 0
    10 | 01 just can make 11.
    00 is still 00. 
    If you have 1, then you can make any bit to 1.
    If you have 1, then you can make any bit to 0.
    contain 1 can make any case contain 1. 
    no one only can fit no one
    */
   //https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal
   //article https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal/discuss/3083822/C%2B%2B-easy-O(N)-with-explanation
public:
    bool makeStringsEqual(string s, string target) {
        int n = s.length();
        int s_cnt0 = 0, t_cnt0 = 0;
        for(auto&c :s) if(c=='0')s_cnt0++;
        for(auto&c :target) if(c=='0')t_cnt0++;
        if(s_cnt0 == n && t_cnt0!=n) return false;
        if(s_cnt0 != n && t_cnt0==n) return false;
        return true;
    }
};