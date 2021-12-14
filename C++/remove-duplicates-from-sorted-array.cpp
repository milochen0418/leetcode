class Solution {
    //https://leetcode.com/problems/remove-duplicates-from-sorted-array
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;        
        int k_idx = 0; 
        for (int j = 1; j < nums.size(); j++) {
            if (nums[k_idx] != nums[j] ) {
                nums[++k_idx] = nums[j];
            }
        }     
        return k_idx + 1; //number of k element in-placed
    }
};