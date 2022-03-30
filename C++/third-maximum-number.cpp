class Solution {
    //https://leetcode.com/problems/third-maximum-number
    //article https://leetcode.com/problems/third-maximum-number/discuss/1897704/C%2B%2B-or-hash-set-or-time-O(N)-space-O(1)
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> s; 
        int n = nums.size();
        for(int i = 0;i<n;i++) {
            s.insert(nums[i]);
            if(s.size()>3) {
                int delmin = INT_MAX;
                for(auto& i:s) delmin = min(i,delmin);
                s.erase(delmin);
            }
        }
        if(s.size()<3) {
            int findmax = INT_MIN;
            for(auto& i:s) findmax = max(i,findmax);
            return findmax;
        } else {
            int find3rdmax = INT_MAX;
            for(auto& i:s) find3rdmax = min(i,find3rdmax);
            return find3rdmax;
        }
        
    }
};