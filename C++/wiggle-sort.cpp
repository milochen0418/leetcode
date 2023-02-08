class Solution {
    //https://leetcode.com/problems/wiggle-sort
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> A = nums;
        int n = nums.size();
        sort(A.begin(), A.end());
        for(int i=0,j=0;i<n;i+=2,j+=1) 
            nums[i] = A[j];
        for(int i=1,j=n-1;i<n;i+=2,j-=1) 
            nums[i] = A[j];
    }
};