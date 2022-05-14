class Solution {
    //https://leetcode.com/problems/permutations-ii
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //solve by the solution in problem next-permutation
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<int> last_nums = nums;
        reverse(last_nums.begin(), last_nums.end());
        
        res.push_back(nums);
        while(last_nums != nums) {
            nextPermutation(nums);
            res.push_back(nums);
        }
        return res;
    }

    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while(i>=0 && nums[i+1] <= nums[i]) i--;
        if(i>=0) {
            int j = nums.size() - 1;
            while(nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }

    vector<vector<int>> permuteUniqueByLibrary(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        res.push_back(nums);
        while (next_permutation(nums.begin(), nums.end())) {
            res.push_back(nums);
        }
        return res;
    }
};