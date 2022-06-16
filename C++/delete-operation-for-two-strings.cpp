class Solution {
    //https://leetcode.com/problems/delete-operation-for-two-strings
public:
    unordered_map<string, unordered_map<string, int>> dp;
    vector<vector<int>> idp;
    string w1,w2;
    int n1,n2;
    int minDistance(string word1, string word2) {
        w1=word1;       w2=word2;
        n1=w1.size();   n2=w2.size();
        idp = vector<vector<int>>(n1, vector<int>(n2,0));
        return sol(0,0);    
        //return sol2(word1, word2);
        //return sol1(word1, word2);
    }
    int sol(int i1, int i2) { //Best Apporach
        if(i1==n1 || i2==n2) return max(n1-i1, n2-i2);
        if(idp[i1][i2] != 0) return idp[i1][i2];
        idp[i1][i2]=(w1[i1]==w2[i2])?sol(i1+1,i2+1):1+min(sol(i1+1,i2), sol(i1,i2+1));
        return idp[i1][i2];
    }

    int sol2(string w1, string w2) { //Approach 2 passed but near TLE
        if(w1.size()==0 || w2.size()==0) return max(w2.size(),w1.size());
        if(dp[w1][w2] != 0) return dp[w1][w2];
        dp[w1][w2] = INT_MAX;
        //The idea is only focus on last character of both w1 and w2
        if(w1[w1.size()-1] == w2[w2.size()-1]) {
            dp[w1][w2] = sol2(w1.substr(0,w1.size()-1), w2.substr(0,w2.size()-1));
        } else {
            dp[w1][w2] = 1+min(
                sol2(w1.substr(0,w1.size()-1), w2),
                sol2(w1, w2.substr(0,w2.size()-1))
            );
        }
        return dp[w1][w2];
    }

    int sol1(string w1, string w2) { //Approach 1 TLE
        if(w1==w2) return 0;
        if(dp[w1][w2] != 0) return dp[w1][w2];
        dp[w1][w2] = INT_MAX;
        if(w1.size()>w2.size()) {
            for(int i = 0; i<w1.size();i++) {
                string w = w1.substr(0,i) + w1.substr(i+1);
                dp[w1][w2] = min(dp[w1][w2],  1 + sol1(w,w2));
            }            
        } else {
            for(int i = 0; i<w2.size();i++) {
                string w = w2.substr(0,i) + w2.substr(i+1);
                dp[w1][w2] = min(dp[w1][w2],  1 + sol1(w1,w));
            }            
        }
        return dp[w1][w2];
    }
};