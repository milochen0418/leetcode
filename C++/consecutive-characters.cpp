class Solution {
    //https://leetcode.com/problems/consecutive-characters
public:
    int maxPower(string s) {
        int ans = 1, n = s.length();
        int j =0;
        for(int i = 1; i<n;i++) 
            if(s[j]!=s[i]) 
                j=i;
            else
                ans = max(ans,i-j+1);
        return ans;
    }
};