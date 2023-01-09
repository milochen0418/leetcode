class Solution {
    //https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number
    //article https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/discuss/3026126/C%2B%2B-Counting-Sort-O(N)
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        int maxv = -1;
        for(auto &i:nums) maxv = max(maxv, i);
        vector<int> mp = vector<int>(maxv+1,0);
        for(auto &i:nums) mp[i]++;
        vector<int> cnt = vector<int>(maxv+1,0);
        cnt[0] = 0;
        for(int i = 1;i<=maxv;i++) 
            cnt[i] = cnt[i-1]+mp[i-1];
        
        for(auto &i:nums) i=cnt[i];
        //For example, 
        //nums = [8,1,2,2,3], then 
        //cnt  = [0,0,1,3,4,4,4,4,4]
        //Let nums[i] = cnt[nums[i]], then
        //nums = [4,0,1,1,3] <-- Our expected answer.
        return nums;        
    }

};