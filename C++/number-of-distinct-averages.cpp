class Solution {
    //https://leetcode.com/problems/number-of-distinct-averages
    //article https://leetcode.com/problems/number-of-distinct-averages/discuss/2877692/C%2B%2B-or-sort-%2B-two-pointer-or-O(NlogN)
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), L=0, R=n-1;
        unordered_set<int> s;
        while(L<R) s.insert(nums[L++] + nums[R--]);
        return s.size();
    }
};