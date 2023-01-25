class Solution {
    //https://leetcode.com/problems/check-if-string-is-decomposable-into-value-equal-substrings
    //article https://leetcode.com/problems/check-if-string-is-decomposable-into-value-equal-substrings/discuss/3098648/C%2B%2B-One-Pass-O(N)
public:
    bool isDecomposable(string s) {
        //Rule 1. Only one element in one time can allow 2+3*n. 
        //Rule 2. All element in every time should all support 3*n rule except rule 1.
        int rule1_cnt = 0;
        int rule2_cnt = 0;
        int cnt = 0, n = s.length();
        char prev = ' ';
        for(int i =0;i<=n;i++) {
            if(i==n || s[i]!=prev) {
                if(cnt%3==2) 
                    rule1_cnt++;
                else if(cnt%3==0)
                    rule2_cnt++;
                else
                    return false;
                prev = s[i];
                if(rule1_cnt>=2) return false;
                cnt = 1;
            } else {
                cnt++;
            }
        }
        return rule1_cnt==1;
    }
};