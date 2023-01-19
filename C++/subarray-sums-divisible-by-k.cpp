class Solution {
    //https://leetcode.com/problems/subarray-sums-divisible-by-k/
public:
    #define printf(...) empty_printf(__VA_ARGS__)
    #define empty_printf(...)
    int subarraysDivByK(vector<int>& nums, int k) {
        //For reduce this problem, we get the math key point here.
        //(prefixSum[j] - prefix[i]) % k = 0 <=> prefixSum[i] % k = prefixSum[j] % k.
        
        int n = nums.size(), ans = 0;
        for(int i = 1;i<n;i++) nums[i]+=nums[i-1];
        
        printf("nums=");
        for(auto &i:nums)printf("%d,",i);
        printf("\n");
        
        vector<int> mods = vector<int>(n,0);
        
        for(int i = 0; i<n;i++) mods[i] = ((nums[i]%k)+k)%k;
        printf("mods=");
        for(auto &i:mods)printf("%d,",i);
        printf("\n");
        vector<int> mp = vector<int>(k,0);
        for(auto &i:mods) mp[i]++;
        mp[0]++;
        printf("mp  =");
        for(auto &i:mp)printf("%d,",i);
        printf("\n");
        
        for(auto &i:mp) i= (i*(i-1))/2;
        printf("mp  =");
        for(auto &i:mp)printf("%d,",i);
        printf("\n");        
        for(auto &i:mp) ans+=i;
        return ans;
    }

    int subarraysDivByK_TLE(vector<int>& nums, int k) {
        //TLE
        int n = nums.size(), ans = 0;
        for(int i = 1;i<n;i++) nums[i]+=nums[i-1];
        for(int i = 0; i<n;i++) {
            for(int j =i;j<n;j++) {
                int nums_i_1 = i==0?0:nums[i-1];
                int sum_i_j = nums[j] - nums_i_1; //sum[i..j]
                if(sum_i_j%k ==0) ans++;
            }
        }
        return ans;
    }
};