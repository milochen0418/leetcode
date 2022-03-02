class Solution {
    //https://leetcode.com/problems/merge-sorted-array/
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        return answer2(nums1, m, nums2, n);
    }
    
    void answer1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = n+m-1;
        while( k>=0) {
            int v1 = i<0?INT_MIN:nums1[i];
            int v2 = j<0?INT_MIN:nums2[j];
            nums1[k--] = v2>v1? nums2[j--]: nums1[i--];
        }
    }
    void answer2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = n+m-1;
        while(i >= 0 && j >= 0) 
            nums1[k--] = (nums1[i] > nums2[j]) ? nums1[i--]: nums2[j--];
        while(j >= 0) 
            nums1[k--] = nums2[j--];                
    }
    
};