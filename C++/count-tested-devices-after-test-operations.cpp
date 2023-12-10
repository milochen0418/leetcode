class Solution {
    //https://leetcode.com/problems/count-tested-devices-after-test-operations
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ans = 0;
        for(auto &i: batteryPercentages) if(i-ans>0) ans++;
        return ans;
    }
};