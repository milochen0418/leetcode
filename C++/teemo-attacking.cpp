class Solution {
    //https://leetcode.com/problems/teemo-attacking
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        timeSeries.push_back(INT_MAX/2);
        int n = timeSeries.size(), ans = 0;
        for(int i = 0;i<n-1;i++) {
            int v = timeSeries[i+1] - timeSeries[i];
            ans+= min(v, duration);
        }
        return ans;
    }
};