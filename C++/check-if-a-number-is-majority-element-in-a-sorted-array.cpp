class Solution {
    //https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int n = nums.size();
        int L=0, R=n-1, M;
        while(L<=R) {
            M = L+(R-L)/2;
            if(target == nums[M]) break;
            if(target<nums[M]) 
                R=M-1;
            else 
                L=M+1;
        }
        if(L>R) return false; //The case of target is not in sorted arry 
        L=M, R=M;
        for(R=M; R<n;R++) if(target!=nums[R])break;
        for(L=M; L>=0;L--) if(target!=nums[L])break;
        return (R-L-1)>n/2;
        
    }
};