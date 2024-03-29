class Solution {
    //https://leetcode.com/problems/sort-an-array
public:
    vector<int> sortArray(vector<int>& nums) {
        
        auto countingSort = [](vector<int>&arr) {
            int minv = INT_MAX;
            int maxv = INT_MIN;
            
            for(auto &i:arr) {
                if(i<minv) minv=i;
                if(i>maxv) maxv=i;
            }
            int diff = maxv-minv;
            for(auto &i:arr) {
                i-=minv;
            }
            int n = arr.size(); 
            //printf("maxv = %d, minv=%d, diff=%d", maxv, minv, diff);
            vector<int> arr1 = vector<int>(n,0);
            vector<int> count_arr = vector<int>(1+diff,0);
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
            for(auto &i:arr) i+=minv;
        };        
        countingSort(nums);
        return nums;       
    }
};