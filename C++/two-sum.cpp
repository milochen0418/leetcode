class Solution {
    //https://leetcode.com/problems/two-sum/
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0; i<n;i++) {
            int b = target - nums[i];
            if(mp.find(b) != mp.end()) {
                return vector<int>{i,mp[b]};
            }
            mp[nums[i]]=i;
        }
        return vector<int>();
    }
    vector<int> twoSumVer01(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0; i<n;i++) mp[nums[i]]=i;
        for(int i = 0; i<n;i++) {
            int b = target-nums[i];
            if(mp.find(b) != mp.end()) {
                if(mp[b] != i) {
                    return vector<int>{i,mp[b]};    
                }
            }
        }
        return vector<int>();
    }
};