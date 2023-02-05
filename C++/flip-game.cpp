class Solution {
    //https://leetcode.com/problems/flip-game
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> ans;
        string &s =currentState;
        int n = s.length();
        for(int i = 0;i<n-1;i++) {
            if(s[i]=='+' && s[i+1]=='+') {
                string news = s;
                news[i]=news[i+1]='-';
                ans.push_back(news);
            }
        }
        return ans;
    }
};