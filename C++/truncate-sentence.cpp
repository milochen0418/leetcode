class Solution {
    //https://leetcode.com/problems/truncate-sentence
public:
    string truncateSentence(string s, int k) {
        int n = s.length();
        for(int i = 0; i<n;i++) {
            if(s[i]==' ') k--;
            if(k==0) {
                s[i]='\0';
                break;
            }
        }
        return string(s.c_str());
    }
};