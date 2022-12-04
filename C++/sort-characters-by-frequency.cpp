class Solution {
    //https://leetcode.com/problems/sort-characters-by-frequency
public:
    string frequencySort(string s) {
        vector<int> mp = vector<int>(256,0);
        for(auto &c: s) mp[c]++;
        sort(s.begin(), s.end(), [&mp](auto&lhs, auto&rhs){
            if(mp[lhs] ==  mp[rhs]) 
                return lhs>rhs;
            else 
                return mp[lhs]> mp[rhs];
        });
        return s;
    }

    string frequencySortVer01(string s) {
        unordered_map<char,int> mp;
        for(auto &c: s) mp[c]++;
        sort(s.begin(), s.end(), [&mp](auto&lhs, auto&rhs){
            if(mp[lhs]> mp[rhs]) {
                return true;
            } else if(mp[lhs]<mp[rhs]){
                return false;
            } else {
                return lhs > rhs;
            }
        });
        return s;
    }
};