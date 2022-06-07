class Solution {
    //https://leetcode.com/problems/merge-sorted-array/
    //article https://leetcode.com/problems/merge-sorted-array/discuss/1811934/C%2B%2B-or-step-by-step-to-improve
    //article https://leetcode.com/problems/merge-sorted-array/discuss/2120854/C%2B%2B-or-1-line-solution-and-explanation
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {

        while(m+n>0) a[m+n] = (m<=0?INT_MIN:a[m-1])>(n<=0?INT_MIN:b[n-1])? a[m---1]:b[n---1];
        /*
        while(m+n>0) {
            int va = (m<=0?INT_MIN:a[m-1]);
            int vb = (n<=0?INT_MIN:b[n-1]);
            a[m+n] = va>vb? a[m---1]:b[n---1];
        }
        */

        /*
		int i = m-1, j = n-1, k = n+m-1;
		while( k>=0) {
			int va = i<0?INT_MIN:a[i];
			int vb = j<0?INT_MIN:b[j];
			a[k--] = vb>va? b[j--]: a[i--];
		}
        */
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

    void answer3(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = n+m-1;
        while( j>=0) {
            int v1 = i<0?INT_MIN:nums1[i];
            int v2 = j<0?INT_MIN:nums2[j];
            nums1[k--] = v2>v1? nums2[j--]: nums1[i--];
        }
    }
};