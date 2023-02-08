class Solution {
    //https://leetcode.com/problems/number-of-lines-to-write-string
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lcnt=1,pcnt=0;
        for(auto &c:s) {
            int w = widths[c-'a'];
            if(pcnt+w<=100) {
                pcnt+=w;
            } else {
                pcnt=w;
                lcnt++;
            }
        }
        return {lcnt, pcnt};
    }
};