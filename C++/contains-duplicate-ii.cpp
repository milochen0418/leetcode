class Solution {
    //https://leetcode.com/problems/contains-duplicate-ii
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++) {
            if(i>k){
                s.erase(nums[i-k-1]);
            }
            int num = nums[i];
            if(s.find(num) == s.end()) {
                s.insert(num);
            } else {
                return true;
            }
        }
        return false;
    }
};