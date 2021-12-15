class Solution {
    //https://leetcode.com/problems/first-missing-positive
public:
    int firstMissingPositive(vector<int>& nums) {
        //The passed answser is rewrite from Plover's Java answer
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums,i, nums[i]-1);
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1 ) {
                return i+1;
            }
        }
        return n+1;

        /*
        unordered_set<int> uset;
        int max = 0;
        for(int num:nums){
            uset.insert(num);
            if(num > max) {
                max = num;
            }
        }
        
        vector<int> v;
        int upmax = max==INT_MAX ? max:max+1;
        for(int i=1; i<=upmax;i++){
            if(uset.find(i) == uset.end()) {
                v.push_back(i);
            }
        }
        
        int min = max+1;
        for(int val: v) {
            if(val<min) {
                min = val; 
            }
        }
        return min;
        */
    }

private:
    void swap(vector<int>& v, int a, int b) {
        int temp = v[a];
        v[a] = v[b];
        v[b] = temp;
    }
};