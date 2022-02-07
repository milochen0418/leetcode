class Solution {
    //https://leetcode.com/problems/max-consecutive-ones/
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0 ;
        int max_cnt = 0;
        for(auto& val: nums) {
            cnt = (val==0)?0:cnt+1;
            max_cnt = max(max_cnt, cnt);
        }
        return max_cnt;
    }
};