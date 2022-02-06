class Solution {
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5043973125625138
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v;
        for(auto n:nums) if(n  < pivot) v.push_back(n);
        for(auto n:nums) if(n == pivot) v.push_back(n);
        for(auto n:nums) if(n  > pivot) v.push_back(n);
        return v;
    }
};