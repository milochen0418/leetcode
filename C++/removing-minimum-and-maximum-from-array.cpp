class Solution {
    //https://leetcode.com/problems/removing-minimum-and-maximum-from-array
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size(), minv=INT_MAX, maxv = INT_MIN, minidx=-1, maxidx=-1;
        for(int i = 0; i<n; i++) {
            int v = nums[i];
            if(v<minv) {
                minidx = i;
                minv = v;
            }
            if (v>maxv) {
                maxidx = i;
                maxv = v;   
            }         
        }
        if(maxidx<minidx) swap(maxidx,minidx);
        int ans = (minidx+1) + (n-maxidx); 
        ans = min(ans, maxidx+1);
        ans = min(ans, n-minidx);
        return ans;
    }
};