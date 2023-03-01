class Solution {
    //https://leetcode.com/problems/sort-an-array/
public:
    vector<int> sortArray(vector<int>& nums) {
        
        for(auto &i:nums) i+=5*1e4;
        auto countingSort = [](vector<int>&arr) {
            int n = arr.size(); 
            vector<int> arr1 = vector<int>(1+10*1e4,0);
            vector<int> count_arr = vector<int>(1+10*1e4,0);
            int x = arr[0];
            for (int i = 1; i < n; i++) if (arr[i] > x) x = arr[i];
            for (int i = 0; i <= x; ++i) count_arr[i] = 0;
            for (int i = 0; i < n; i++) count_arr[arr[i]]++;
            for (int i = 1; i <= x; i++) count_arr[i] += count_arr[i - 1];
            for (int i = n - 1; i >= 0; i--) {
                arr1[count_arr[arr[i]] - 1] = arr[i];
                count_arr[arr[i]]--;
            }
            for (int i = 0; i < n; i++)  arr[i] = arr1[i];
        };        
        countingSort(nums);
        for(auto &i:nums) i-=5*1e4;
        return nums;
        
    }
};