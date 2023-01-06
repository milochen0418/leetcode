class Solution {
    //https://leetcode.com/problems/rank-transform-of-an-array
    //article https://leetcode.com/problems/rank-transform-of-an-array/discuss/3009503/C%2B%2B-Hash-Map
public:
    vector<int>& arrayRankTransform(vector<int>& arr) {
        unordered_set<int> s;
        unordered_map<int,int> mp;
        vector<int> v;
        for(auto &i:arr) s.insert(i);
        for(auto &i:s) v.push_back(i);
        sort(v.begin(), v.end());
        for(int i = 0;i<v.size();i++) mp[v[i]] = i+1;
        for(int i = 0;i<arr.size();i++) arr[i] = mp[arr[i]];
        return arr;      
    }
};