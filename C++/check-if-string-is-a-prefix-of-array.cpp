class Solution {
    //https://leetcode.com/problems/check-if-string-is-a-prefix-of-array
    //article https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/discuss/2910455/C%2B%2B-or-O(N)
public:
    bool isPrefixString(string s, vector<string>& words) {
        int i=0,j=0,k=0,n=s.length(), m=words.size();
        for(auto &w:words) {
            for(auto &c:w) {
                if(c==s[i]) {
                    i++;
                } else {
                    return false;
                }
            }
            if(i>=n) return true;
        }
        return false;
    }
};