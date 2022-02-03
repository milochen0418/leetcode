class Solution {
    //https://leetcode.com/problems/4sum-ii
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        vector<vector<int>> v = {nums1, nums2, nums3, nums4};
        vector<int> idx={0,0,0,0};
        int m = v.size(); //4
        int cnt = 0;
        int len=n*n*n*n; //2^30.5.  Since //log(200*200*200*200) / log(2) = 30.5 
        int i = 0;
        for(i=0;i<len;i++) { //0 to 15
            int t = i; //asume t = 15
            for(int j=0;j<m;j++) { //0-1
                idx[j]=t % n; //15%2 =1, 7%2 =1, 3%2 =1, 1%2 =1 
                t = t / n;//15=15/2=  7, 7/2 =3, 3/2 =1, 1/2 =0
            }
            int sum = 0;
            for(int j=0;j<m;j++) {
                sum = sum + v[j][idx[j]];
            }
            if(sum == 0) cnt++;
        }
        return cnt;
    }
};