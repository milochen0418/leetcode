class Solution {
    //https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product
public:
    int getMaxLen(vector<int>& nums) {
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