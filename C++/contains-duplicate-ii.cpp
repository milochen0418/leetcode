class Solution {
    //https://leetcode.com/problems/contains-duplicate-ii
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<n;i++) {
            unordered_set<int> s;
            for(int j=0;j<=k;j++) {
                if(i+j>=n) break;
                int num = nums[i+j];
                if(s.find(num) == s.end()) {
                    s.insert(num);
                } else {
                    return true;
                }
            }      
        }
        return false;
    }
};