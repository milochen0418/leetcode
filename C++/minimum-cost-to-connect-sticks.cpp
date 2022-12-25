class Solution {
    //https://leetcode.com/problems/minimum-cost-to-connect-sticks/
public:
    int connectSticks(vector<int>& sticks) {
        int n = sticks.size(),ans = 0;;
        sort(sticks.begin(), sticks.end());
        for(int i = 1;i<n;i++) {
            sticks[i] = sticks[i-1]+sticks[i];
            ans+=sticks[i];
        }
        return ans;
    }
};