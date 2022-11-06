class Solution {
    //https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
public:
    /*
    [1,5,4,2,9,9,9]  
    
    cnt_mp[9] = 3
    vk[3] = 1
    vk[2] =1
    vk[1] =1
    
    */
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> cnt_mp;
        int n = nums.size();
        
        long long ans = 0;
        vector<int> vk = vector<int>(k+1,0);
        vk[0] = k;
        long long subarray_sum = 0;
        for(int i = 0; i <k;i++) {
            vk[cnt_mp[nums[i]]] -= 1;
            //vk[cnt_mp[nums[i]] 
            cnt_mp[nums[i]] = cnt_mp[nums[i]]+1;
            vk[cnt_mp[nums[i]]] += 1;
            subarray_sum = subarray_sum + (long long)nums[i];
        }
        if(vk[1] == k) {
            ans = subarray_sum;
        }
    
        for(int i = 1; i <= n-k;i++) {
            subarray_sum -= nums[i-1];
            vk[cnt_mp[nums[i-1]]] -= 1;
            cnt_mp[nums[i-1]] -= 1;
            vk[cnt_mp[nums[i-1]]] += 1;

            subarray_sum += nums[i+k-1];
            vk[cnt_mp[nums[i+k-1]]] -= 1;
            cnt_mp[nums[i+k-1]] += 1;
            vk[cnt_mp[nums[i+k-1]]] += 1;

            if(vk[1] == k) {
                ans = max(subarray_sum ,ans);
            }

        }

        return ans;
    }
};