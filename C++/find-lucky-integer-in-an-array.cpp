class Solution {
    //https://leetcode.com/problems/find-lucky-integer-in-an-array
public:
    int findLucky(vector<int>& arr) {
        vector<int> mp = vector<int>(501,0);
        for(auto &i:arr) mp[i]++;
        for(int i = 500;i>=1;i--) 
            if(mp[i] == i) return i;
        return -1;
    }
};