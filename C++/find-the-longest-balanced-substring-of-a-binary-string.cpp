class Solution {
    //https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/
public:
    int findTheLongestBalancedSubstring(string s) {
        int maxv = 0;
        int n = s.length();
        for(int begin = 0;begin<n;begin++) {
            int i = begin, cnt0=0, cnt1=0;
            while(i<n && s[i]=='0') {
                i++;
                cnt0++;
            }
            while(i<n && s[i]=='1') {
                i++;
                cnt1++;
            }
            int v = min(cnt0,cnt1);
            maxv = max(maxv,v);
        }
        return maxv*2;
    }
};