class Solution {
    //https://leetcode.com/problems/delete-characters-to-make-fancy-string/
public:
    string makeFancyString(string s) {
        string ans;
        char prev_c = 0;
        int cnt=0;
        for(auto &c: s) {
            if(prev_c == c) {
                cnt++;
            } else {
                cnt=1;
            }
            prev_c = c;
            if(cnt<=2) {
                ans.push_back(c);
            }
        }
        return ans;
    }
};