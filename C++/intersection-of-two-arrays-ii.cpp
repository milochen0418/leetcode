class Solution {
    //https://leetcode.com/problems/intersection-of-two-arrays-ii
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        /*
        printf("\nnums1=");
        for(auto &i:nums1)printf("%d,",i);
        printf("\nnums2=");
        for(auto &i:nums2)printf("%d,",i);
        printf("\n");
        */
        vector<int> ans;
        vector<int>&a = nums2;
        int initL = 0;
        for(auto &t:nums1) {
            //printf("initL=%d, find t=%d\n",initL,t);
            int n = a.size(), L=initL,R=n-1;
            while(L<=R) {
                int M = L+ (R-L)/2;
                //printf("M=%d\n",M);
                if(a[M] == t && (M-1<initL || a[M-1]<t)) {
                    ans.push_back(t);
                    initL = M+1;
                    //printf("push_back t=%d, a[M=%d]=%d\n", t,M,a[M]);
                    break;
                }
                if(t<=a[M]) R=M-1; else L=M+1;
                
            }
        }
        return ans;
    }
};


/*
testcase passed
[4,5,9]
[4,4,8,9,9]
[1,2,2,1]
[2,2]
[1,2,2,1]
[2]

testcase failed
[61,24,20,58,95,53,17,32,45,85,70,20,83,62,35,89,5,95,12,86,58,77,30,64,46,13,5,92,67,40,20,38,31,18,89,85,7,30,67,34,62,35,47,98,3,41,53,26,66,40,54,44,57,46,70,60,4,63,82,42,65,59,17,98,29,72,1,96,82,66,98,6,92,31,43,81,88,60,10,55,66,82,0,79,11,81]
[5,25,4,39,57,49,93,79,7,8,49,89,2,7,73,88,45,15,34,92,84,38,85,34,16,6,99,0,2,36,68,52,73,50,77,44,61,48]
Output   [0,4,5,6,38,44,45,57,61,77,79,85,88,89,92]
Expected [5,4,57,79,7,89,88,45,34,92,38,85,6,0,77,44,61]





[0,1,3,4,5,5,6,7,10,11]
[0,2,2,4,5,6,7,7,8,15]
*/