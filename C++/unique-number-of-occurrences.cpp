class Solution {
    //https://leetcode.com/problems/unique-number-of-occurrences/
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        unordered_set<int> s;
        for(auto &i: arr) mp[i]++; 
        for(auto &[k,v]: mp) s.insert(v);
        return s.size() == mp.size();
    }
};