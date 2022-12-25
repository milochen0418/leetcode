class Solution {
    //https://leetcode.com/problems/find-center-of-star-graph
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> mp;
        mp[edges[0][0]]++;
        mp[edges[0][1]]++;
        mp[edges[1][0]]++;
        mp[edges[1][1]]++; 
        for(auto &[k,v]:mp) {
            if(v==2) return k;
        }
        return -1;
    }
};