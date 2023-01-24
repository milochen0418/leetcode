class Solution {
    //https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product
    //article https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/discuss/2214627/C%2B%2B-or-time-O(N)-space-O(1)-or-explanation
public:
    int getMaxLen(vector<int>& nums) {
        //positive is mean value >= 1 here. zero is not mean positive
        //Idea 1. find the following
        //The maximum subarray between [start or zero ..  end or zero] and there 
        //are even number of negative value in it. 
        // For overflow problem of multiply
        // Think about the case [-1,2]. And we need to reverse to do it again.
        //(1) Just need to flat out all value into 1,0 and -1.
        for(auto &i:nums) if(i!=0) i = i/abs(i);
        
        int ans = 0;
        function<void(vector<int>&)> travel = [&ans](vector<int>& A){
            int v = 1, len = 0;
            for(auto &i:A) {
                if(i==0) {
                    v=1;
                    len=0;
                } else {
                    v*=i;
                    len++;
                    if(v>0) ans=max(ans,len);
                }
            }
        };
        travel(nums);
        reverse(nums.begin(),nums.end());
        travel(nums);
        return ans;
    }

    int getMaxLen_v01(vector<int>& nums) {
        nums.push_back(0);
        int ans = sol(nums);
        reverse(nums.begin(), nums.end());
        nums.push_back(0);
        return max(ans, sol(nums));
    }
    int sol(vector<int> & nums) {
		int a = 0, c = 1;//a:ans, c:candidate 
        int len=0;
        int neg=0;
        int idx=0;
        for(auto &v: nums) {
            if(v==0) {
                if(neg%2==0) {
                    a = max(a,len);
                } else {
                    int i = idx;
                    while(nums[i]>=0) {
                        i--;
                        len--;
                    }
                    a = max(a,len);
                }
                len = 0;
                neg = 0;
                
            } else {
                len++;
                if(v<0)neg++;
            }
            idx++;
        }	
		return a;
    }
};