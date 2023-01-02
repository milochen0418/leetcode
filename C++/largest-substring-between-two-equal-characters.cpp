class Solution {
    //https://leetcode.com/problems/largest-substring-between-two-equal-characters
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();
        vector<vector<int>> mp=vector<vector<int>>(256,vector<int>());
        for(int i = 0;i<n;i++)
            mp[s[i]].push_back(i);
        
        int maxv = 0;
        for(int i='a';i<='z';i++) 
            if(mp[i].size()>=2)
                maxv = max(maxv, mp[i].back()-mp[i][0]);
        
                
        return maxv-1;
    
    }
};