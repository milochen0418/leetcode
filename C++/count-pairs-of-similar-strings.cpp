class Solution {
    //https://leetcode.com/problems/count-pairs-of-similar-strings
public:
    int similarPairs(vector<string>& words) {
        int ans=0, n = words.size();
        vector<vector<char>> features(n, vector<char>()) ;
        for(int i = 0; i<n;i++) {
            string &s = words[i];
            vector<char> &v= features[i];
            unordered_set<char> ss;
            for(auto &c:s) ss.insert(c);
            for(auto &c:ss) v.push_back(c);
            sort(v.begin(), v.end());
        }
        
        for(int i = 0;i<n;i++) 
            for(int j = i+1;j<n;j++) 
                if(features[i] == features[j]) ans++;
        return ans;
    }
    
};