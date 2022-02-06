class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v;
        for(auto n:nums) if(n  < pivot) v.push_back(n);
        for(auto n:nums) if(n == pivot) v.push_back(n);
        for(auto n:nums) if(n  > pivot) v.push_back(n);
        return v;
    }
};