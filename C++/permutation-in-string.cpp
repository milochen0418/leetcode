class Solution {
    //https://leetcode.com/problems/permutation-in-string/
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length(), n = s2.length();
        if(k>n) return false;
        vector<int> mp1 = vector<int>(26,0), mp2=mp1;
        for(auto &c:s1) mp1[c-'a']++;
        for(int i = 0;i<k;i++) mp2[s2[i]-'a']++;
        if(mp1==mp2) return true;
        
        for(int i = k;i<n;i++) {
            mp2[s2[i]-'a']++;
            mp2[s2[i-k]-'a']--;
            if(mp2==mp1) return true;
        }
        return false;
    }
};