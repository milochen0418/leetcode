class Solution {
    //https://leetcode.com/problems/count-subarrays-with-median-k
public:
    int countSol(vector<int>&vk, int &q, int added) {
        int n = vk.size(), ans=0;
        unordered_map<int,vector<int>> mpL, mpR;
        for(int L = 0; L<=q;L++) mpL[getSum(L,q,vk)+added].push_back(L); 
        for(int R = q;R<n;R++) mpR[getSum(q,R,vk)].push_back(R);
        for(auto& [sum,idxs]:mpL) ans+=idxs.size() * mpR[sum*-1].size();
        return ans;
    }

    int getSum(int L, int R, vector<int> &vk) {//return sum of vk'[L..R]
        int vk_R = vk[R], vk_L_1 = (L==0)?0:vk[L-1];
        return vk_R-vk_L_1;
    }

    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), q=0;//q will be index of k in nums
        vector<int> vk = vector<int>(n,0);        
        for(int i = 0; i<n; i++) if((nums[i]-k)!=0) vk[i] = abs(nums[i]-k)/(nums[i]-k); //e.g. [3,2,1,4,5], k = 4, then let vk' = [-1,-1,-1,0,1]
        for(int i = 1; i<n; i++) vk[i] = vk[i-1] + vk[i]; //let vk be the prefix sum of vk'. 
        for(int i = 0;i<n;i++) if(nums[i] == k) q = i;
        return countSol(vk,q,0)+countSol(vk,q,-1);
    }
};