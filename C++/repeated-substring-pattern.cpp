class Solution {
    //https://leetcode.com/problems/repeated-substring-pattern
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        vector<int> v; 
        for(int i = 1; i<n; i++) if(n%i==0) v.push_back(i);
        for(auto &k: v) { 
            int i = 0;
            while(i<n && s[i]==s[i%k]) i++;
            if(i==n) return true;
        }
        return false;
    }
};