class Solution {
    //https://leetcode.com/problems/maximum-population-year
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> v = vector<int>(100,0);
        int maxv=0, maxyear=1950;
        for(int i = 1950;i<2050;i++) {
            for(auto &l:logs) {
                v[i-1950]+=(i>=l[0] && i<l[1]);
            }
            if(v[i-1950]>maxv) {
                maxv = v[i-1950];
                maxyear = i;
            }
        }
        return maxyear;
    }
};