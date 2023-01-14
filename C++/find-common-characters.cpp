class Solution {
    //https://leetcode.com/problems/find-common-characters
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> v = vector<int>(26,INT_MAX);
        for(auto &w:words) {
            vector<int> u = vector<int>(26,0);
            for(auto &c:w) u[c-'a']++;
            for(int i = 0; i<26;i++) v[i] = min(v[i], u[i]);
        }
        vector<string> ans;
        //generate answer from v
        for(int i = 0; i<26;i++) {
            int k = v[i];
            if(k==0) continue;
            char c = i+'a';
            string s = string(1,c);
            for(int j = 0;j<k;j++) {
                ans.push_back(s);
            }
        }
        return ans;
    }
    
};