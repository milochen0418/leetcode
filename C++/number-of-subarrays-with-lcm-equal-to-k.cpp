class Solution {
public:
    //https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/
    //Good refer of LCM. : https://zh.wikipedia.org/wiki/%E6%9C%80%E5%B0%8F%E5%85%AC%E5%80%8D%E6%95%B8
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0; 
        
        for(int i = 0; i<n;i++) {
            unsigned long long cur = nums[i];
            if(cur == k) ans++;
            for(int j = i+1;j<n;j++) {
                if(cur>k) break;
                cur = lcm(cur, nums[j]);
                if(cur == k) ans++;
            }
        }   
        return ans;
    }
    /*
    long long lcm(long long a,long long b) {
        return (abs(a*b)/gcd(a,b) );
    }*/
};