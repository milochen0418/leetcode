class Solution {
    //https://leetcode.com/problems/shortest-word-distance
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int ans = INT_MAX, j1=-1,j2=-1;
        vector<pair<string,int>> vs;
        for(int i = 0; i<wordsDict.size();i++) {
            string &w = wordsDict[i];
            if(w == word1 || w == word2) vs.push_back({w,i});
        }
        for(int i = 0; i<vs.size();i++) {
            (vs[i].first==word1?j1:j2)=vs[i].second;
            if(j1>=0 && j2>=0) ans = min(ans, abs(j2-j1));
        }
        return ans;
    }

    int shortestDistance_v01(vector<string>& wordsDict, string word1, string word2) {
        vector<pair<string,int>> vs;
        for(int i = 0; i<wordsDict.size();i++) {
            string &w = wordsDict[i];
            if(w == word1 || w == word2) vs.push_back({w,i});
        }
        int ans = INT_MAX;
        int j1=-1,j2=-1;//j1 chase the index of word1, j2 chase the index of word2
        for(int i = 0; i<vs.size();i++) {
            if(vs[i].first==word1) {
                j1=vs[i].second;
            } else {
                j2=vs[i].second;
            }
            if(j1>=0 && j2>=0) ans = min(ans, abs(j2-j1));
        }
        return ans;
    }
};