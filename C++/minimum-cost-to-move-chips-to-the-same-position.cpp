class Solution {
    //https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position
public:
    int minCostToMoveChips(vector<int>& position) {
        vector<int> v = vector<int>(2,0);
        for(auto &p: position) v[p%2]++;
        return min(v[0],v[1]);
    }
};