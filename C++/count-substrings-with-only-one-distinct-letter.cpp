class Solution {
    //https://leetcode.com/problems/count-substrings-with-only-one-distinct-letter
public:
    int countLetters(string s) {
        s.push_back('+');
        int cnt = 1, n = s.length(), ans = 0;
        for(int i = 1;i<n;i++) 
            if(s[i] == s[i-1]) 
                cnt++;
            else {
                ans+=(cnt*(cnt+1))/2;
                cnt = 1;
            }
        return ans;
    }
};