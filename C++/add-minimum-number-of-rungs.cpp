class Solution {
    //https://leetcode.com/problems/add-minimum-number-of-rungs
    //article https://leetcode.com/problems/add-minimum-number-of-rungs/discuss/4187751/C%2B%2B-or-One-Pass-O(N)-simple-7-lines
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