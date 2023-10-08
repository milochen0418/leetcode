class Solution {
    //https://leetcode.com/problems/number-of-employees-who-met-the-target
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans=0;
        for(auto &h: hours) ans+=(h>=target);
        return ans;
    }
};