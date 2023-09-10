class Solution {
    //https://leetcode.com/problems/points-that-intersect-with-cars
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        unordered_set<int> s;
        for(auto &v : nums) {
            for(int i  = v[0]; i<=v[1]; i++) {
                s.insert(i);
            }
        }
        return s.size();
    }
};