class Solution {
    //https://leetcode.com/problems/add-minimum-number-of-rungs
public:
    int addRungs(vector<int>& rungs, int dist) {
        int prev = 0, ans = 0;
        for(auto &i : rungs) {
            ans += (i-prev)/dist;
            ans -= (0==(i-prev)%dist);
            prev = i;
        }
        return ans;
    }
};