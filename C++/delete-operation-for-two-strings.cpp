class Solution {
    //https://leetcode.com/problems/delete-operation-for-two-strings
public:
    unordered_map<string, unordered_map<string, int>> dp;
    int minDistance(string word1, string word2) {
        return sol2(word1, word2);        
    }

    int sol2(string w1, string w2) { //pass but near TLE
        if(w1.size()==0 || w2.size()==0) return max(w2.size(),w1.size());
        if(dp[w1][w2] != 0) return dp[w1][w2];
        dp[w1][w2] = INT_MAX;
        //The idea is only focus on last character of both w1 and w2
        if(w1[w1.size()-1] == w2[w2.size()-1]) {
            dp[w1][w2] = sol(w1.substr(0,w1.size()-1), w2.substr(0,w2.size()-1));
        } else {
            dp[w1][w2] = 1+min(
                sol(w1.substr(0,w1.size()-1), w2),
                sol(w1, w2.substr(0,w2.size()-1))
            );
        }
        return dp[w1][w2];
    }

    int sol1(string w1, string w2) {//TLE
        if(w1==w2) return 0;
        if(dp[w1][w2] != 0) return dp[w1][w2];
        dp[w1][w2] = INT_MAX;
        if(w1.size()>w2.size()) {
            for(int i = 0; i<w1.size();i++) {
                string w = w1.substr(0,i) + w1.substr(i+1);
                dp[w1][w2] = min(dp[w1][w2],  1 + sol(w,w2));
            }            
        } else {
            for(int i = 0; i<w2.size();i++) {
                string w = w2.substr(0,i) + w2.substr(i+1);
                dp[w1][w2] = min(dp[w1][w2],  1 + sol(w1,w));
            }            
        }
        return dp[w1][w2];
    }
};