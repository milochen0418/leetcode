class Solution {
    //https://leetcode.com/problems/missing-ranges/
    //article https://leetcode.com/problems/missing-ranges/discuss/2314209/C%2B%2B-or-time-O(N)
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans=vector<string>();
        int n = nums.size();
        if(n==0) {
            ans.push_back(sget(lower,upper));
            return ans;
        }
        
        int begin=0, end=n-1;
        for(int i = 0;i <n;i++) if(lower<=nums[i]) break; else begin=i;
        for(int i=n-1;i>=0;i--) if(upper>=nums[i]) break; else end=i;
        
        //printf("lower=%d, begin=%d, nums[begin]=%d\n",lower, begin, nums[begin]);
        if(lower<nums[begin]) ans.push_back(sget(lower,nums[begin]-1));
        
        for(int i = begin+1; i<=end;i++) {
            int a = nums[i-1];
            int b = nums[i];
            if(b-a>1) ans.push_back(sget(a+1,b-1));
        }
        //printf("upper=%d, end=%d, nums[end]=%d\n",upper, end, nums[end]);
        if(upper>nums[end]) ans.push_back(sget(nums[end]+1, upper));
        return ans;
    }
    string sget(int L,int R) {
        if(L==R) return to_string(L);
        return to_string(L)+"->"+to_string(R);
    }
};