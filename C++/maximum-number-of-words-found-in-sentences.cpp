class Solution {
    //https://leetcode.com/problems/maximum-number-of-words-found-in-sentences
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans=0;
        for(auto &s: sentences) {
            int tmp=1;
            for(auto &c:s) tmp+=(c==' ');
            ans = max(ans, tmp);
        }
        return ans;
    }
};