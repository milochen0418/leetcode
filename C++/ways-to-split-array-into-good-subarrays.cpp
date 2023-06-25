class Solution {
    //https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/
public:
    
    /*
    01001
    0100100000
    
    1 0 0 1
    
    1|0 0 1
    1 0|0 1
    1 0 0|1
    
    2個0 -> 切3種可能
    
    m個0 產生 m+1 個可能
    
    
    
    
    */
    /*
    (1) 0000  -> 0 
    
    01000100001000
    0............n-1
    
     1000100001   -->(2) 
     L        R
     
    
    --(3) 
    4*5 
    1|0|0|0|100001
    
    1|0|0|1
    */
    typedef long long ll;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        ll mod = 1e9+7;
        int n = nums.size();
        int L = 0, R = n-1;
        /*
        int allzero = 1;
        for(int i = 0; i<n;i++) {
            if(nums[i] == 1) {
                allzero = 0;
                break;
            }
        }
        if(allzero) return 0;
        */
        while(L<n && nums[L]==0) L++;
        while(R>=0 && nums[R]==0) R--;
        if(L>R) return 0;
        if(L==R) return 1;
        
        vector<int> v; 
        int cnt = 0;
        for(int i = L;i<=R;i++) {
            if(nums[i]==1) {
                v.push_back(cnt+1);
                cnt= 0;
            } else {
                cnt++;
            }
        }
        ll prod = 1;
        for(auto &i:v)  {
            ll d = i;
            prod = prod * d;
            prod = prod % mod;
        }
        
        return (int)prod;        
    }
};