class Solution {
    //https://leetcode.com/problems/relative-sort-array
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> mp = vector<int>(1001,-1);//mapping arr2's element to its index
        for(int i = 0; i<arr2.size();i++) mp[arr2[i]] = i;
        sort(arr1.begin(), arr1.end(), [&](auto &lhs, auto &rhs) {        
            if(mp[rhs] != -1 && mp[lhs] != -1) return mp[lhs] < mp[rhs];
            if(mp[lhs]!=-1) return true;
            if(mp[rhs]!=-1) return false;
            return lhs<rhs;
        });
        return arr1;
    }

    vector<int> relativeSortArray_v01(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;//mapping arr2's element to its index
        for(int i = 0; i<arr2.size();i++) mp[arr2[i]] = i;
        sort(arr1.begin(), arr1.end(), [&](auto &lhs, auto &rhs){
            if(mp.find(rhs) != mp.end() && mp.find(lhs)!=mp.end()) {
                return mp[lhs] < mp[rhs];
            } 
            if(mp.find(lhs)!=mp.end()) return true;
            if(mp.find(rhs)!=mp.end()) return false;
            return lhs<rhs;
        });
        return arr1;
    }
};