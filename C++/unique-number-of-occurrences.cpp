class Solution {
    //https://leetcode.com/problems/unique-number-of-occurrences/
    //add article https://leetcode.com/problems/unique-number-of-occurrences/discuss/2862094/C%2B%2B-or-O(N)-or-6-lines-or-hash-map-and-hash-set
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        unordered_set<int> s;
        for(auto &i: arr) mp[i]++; 
        for(auto &[k,v]: mp) s.insert(v);
        return s.size() == mp.size();
    }
};