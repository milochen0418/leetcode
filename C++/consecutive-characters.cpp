class Solution {
    //https://leetcode.com/problems/consecutive-characters
public:
    int maxPower(string s) {
        int ans = 1, n = s.length();
        if(n==0)return 0;
        unordered_map<char,int> mp;
        int j =0;
        for(int i = 1; i<n;i++) 
            if(s[j]!=s[i]) 
                j=i;
            else
                ans = max(ans,i-j+1);
        return ans;
    }
};