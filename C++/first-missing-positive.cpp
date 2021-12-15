class Solution {
    //https://leetcode.com/problems/first-missing-positive
public:
    int firstMissingPositive(vector<int>& nums) {
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
    }
};