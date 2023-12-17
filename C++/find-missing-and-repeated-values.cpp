class Solution {
    //https://leetcode.com/problems/find-missing-and-repeated-values
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int a=0,b=0;
        unordered_map<int,int>mp;
        for(auto &v:grid) 
            for(auto &i:v)
                mp[i]++;
        for(int i = 1;i<=n*n;i++) {
            if(mp[i]==0) b=i;
            if(mp[i]==2) a=i;
        }
        return {a,b};
        
    }
};