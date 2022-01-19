class Solution {
    //https://leetcode.com/problems/word-break
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        int n = s.length();
        vector<vector<int>>dp (n+1, vector<int>(n+1, -1));
        for(auto word: wordDict) words.insert(word);
        int val = wordbreak(s, words, dp,0,n);
        return val > 0;
    
    }
    
    int wordbreak( const string& s, unordered_set<string>& words, vector<vector<int>>&dp,int i ,int j) {
        
        if(dp[i][j] > -1) return dp[i][j];
        if(i==j) return dp[i][j] = 1;
        
        int len = j-i;
        if(words.count(s.substr(i,len))>0) {
            dp[i][j] = 1;
            return dp[i][j];
        } else {
            dp[i][j] = 0;
            for(int k=i+1;k<j;k++) {
                dp[i][k] = wordbreak(s, words, dp, i,k);
                dp[k][j] = wordbreak(s, words, dp, k,j);
                dp[i][j] = max(dp[i][j], dp[i][k]*dp[k][j]);
            }
            return dp[i][j];
        }
    }
};