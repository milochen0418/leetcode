class Solution {
    //https://leetcode.com/problems/check-if-all-as-appears-before-all-bs
public:
    bool checkString(string s) {
        int n = s.length();
        int state = 0;
        char prev_letter = 'a';
        for(int i = 0;i<n;i++) {
            if(state == 0) {
                if(prev_letter != s[i]) {
                    state =1;
                }
            } else { //state = 1
                if(s[i] == 'a') return false;
            }
        }
        return true;
    }
};