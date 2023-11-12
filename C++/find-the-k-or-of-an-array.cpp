class Solution {
    //https://leetcode.com/problems/find-the-k-or-of-an-array
    //article https://leetcode.com/problems/find-the-k-or-of-an-array/discuss/4279520/C%2B%2B-or-One-Pass-for-every-bit
public:
    int findKOr(vector<int>& nums, int k) {
        unsigned int cnt=0,n=nums.size(),ans=0,base=1;
        while(1) {
            int sum=0;
            int zerocnt=0;
            for(auto &v: nums) {
                if(v==0) {
                    zerocnt++;
                    continue;
                }
                sum+=v%2;
                v/=2;
            }
            if(zerocnt>=n) break;
            if(sum>=k)ans+=base;
            cnt++;
            base*=2;//unsgined int for base is okay 
        }
        return ans;
    }
};