class Solution {
    //https://leetcode.com/problems/find-the-highest-altitude
public:
    int largestAltitude(vector<int>& gain) {
        int high = 0;
        int ans = 0;
        for(auto &g: gain) {
            high+=g;
            ans = max(ans, high);
        }
        return ans;
    }
};