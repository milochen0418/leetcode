class Solution {
    //https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/
    //add article https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/discuss/2592120/C%2B%2B-or-Time-O(N)-Space-O(1)
public:
    int longestContinuousSubstring(string s) {
        int n = s.length();
        int ans = 1;
        int cnt = 1;
        for(int i = 1;i<n;i++) {
            if(s[i-1]+1 == s[i]) {
                cnt++;
                ans=max(ans,cnt);
            } else {
                cnt = 1;
            }
        }
        return ans;
    }
};