class Solution {
    //https://leetcode.com/problems/destination-city
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        for(auto &p: paths) s.insert(p[0]);
        for(auto &p: paths) if(s.find(p[1])==s.end()) return p[1]; 
        return "";
    }
};