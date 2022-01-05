class Solution {
    //https://leetcode.com/problems/median-of-two-sorted-arrays
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int mid_idx = 0; 
        int A_idx = 0;
        int B_idx = 0;
        int A_len = A.size();
        int B_len = B.size();
        int total_len = A_len + B_len;
        int old_indexed_val = 0; 
        int indexed_val = 0; 
        
        mid_idx = (total_len)/2;
        while( A_idx + B_idx <= mid_idx) { 
            int A_val = (A_idx < A_len) ? A[A_idx] : INT_MAX;
            int B_val = (B_idx < B_len) ? B[B_idx] : INT_MAX;
            if(A_val < B_val) {
                old_indexed_val = indexed_val;
                indexed_val = A[A_idx++];
            } else {
                old_indexed_val = indexed_val;
                indexed_val = B[B_idx++];
            }
        }
        
        
        if((total_len) % 2 == 1) {    
            return indexed_val;
        } else {
            return (double)(indexed_val + old_indexed_val) /2;
        }

    }
};