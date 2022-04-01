class Solution {
    //https://leetcode.com/problems/reverse-string
    //article https://leetcode.com/problems/reverse-string/discuss/1902008/C%2B%2B-or-two-pointer
public:
    void reverseString(vector<char>& s) {
        int L = 0, R = s.size()-1;
        while(L<R) swap(s[L++],s[R--]);
    }
};