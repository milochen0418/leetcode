class Solution {
    //https://leetcode.com/problems/count-tested-devices-after-test-operations
    //article https://leetcode.com/problems/count-tested-devices-after-test-operations/discuss/4385215/C%2B%2B-or-simple-3-lines-O(N)
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ans = 0;
        for(auto &i: batteryPercentages) if(i-ans>0) ans++;
        return ans;
    }
};