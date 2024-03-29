class Solution {
    //https://leetcode.com/problems/find-smallest-common-element-in-all-rows
    //aritcle https://leetcode.com/problems/find-smallest-common-element-in-all-rows/discuss/4405158/C%2B%2B-simple-hash-map-solution
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        unordered_map<int,int>mp;
        int m = mat.size(), n=mat[0].size();
        for(auto &v:mat)
            for(auto &i:v)
                mp[i]++;
        int ans = INT_MAX;
        for(auto &[k,v]:mp) 
            if(v==m) ans = min(k,ans);
        return ans==INT_MAX?-1:ans;
    }
};