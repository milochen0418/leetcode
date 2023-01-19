class Solution {
    //https://leetcode.com/problems/maximum-subarray
    //article https://leetcode.com/problems/maximum-subarray/discuss/2207120/C%2B%2B-or-greedy-approach-space-O(N)-time-O(1)-or-from-idea-to-proof
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5449522045070242/
    //article https://leetcode.com/problems/maximum-subarray/discuss/3067003/C%2B%2B-Prefix-Sum-or-O(N2)-greater-O(N)

public:
    int maxSubArray(vector<int>& nums) {
        //Refer the idea from Bangye Wu in https://www.facebook.com/groups/1451299754892511/posts/6053093378046436/
        int n = nums.size();
        int ans = INT_MIN;
        int prefix_min = 0;
        int Si = 0;
        for(auto &i: nums){
            Si = Si + i;
            ans = max(ans, Si-prefix_min);
            prefix_min = min(prefix_min, Si);
        }        
        return ans;
    }

    int maxSubArray_v01_BangyeWu(vector<int>& nums) {
        //Refer the idea from Bangye Wu in https://www.facebook.com/groups/1451299754892511/posts/6053093378046436/
        int n = nums.size();
        int ans = INT_MIN;
        int prefix_min = 0;
        for(int i = 0; i<n; i++) {
            int nums_i_1 = i==0 ? 0 : nums[i-1];
            nums[i] += nums_i_1; //S[i]
            ans = max(ans, nums[i] - prefix_min);
            prefix_min = min(prefix_min, nums[i]);//prefix-minimum    
        }
        return ans;
    }
    //greedy algorithm
    int maxSubArray_greedy(vector<int>& nums) {
        /*
        [-2,1,-3,4,-1,2,1,-5,4]
        case [L,R]=[0,0]
        [-2] -> -2
        case [L,R]=[1,1]
        [1] -> 1
        case [L,R]=[1,2]
        [1,-3] -> -2
        case [L,R]=[3,3]
        [4] -> 4
        case [L,R]=[3,4]
        [4,-1] -> 3
        case [L,R]=[3,5]
        [4,-1,2] -> 5
        case [L,R]=[3,6]
        [4,-1,2,1] -> 6   <---- max
        case [L,R]=[3,7]
        [4,-1,2,1,-5] -> 1
        case [L,R]=[3,8]
        [4,-1,2,1,-5,4] -> 5
        */ 
        int ans = INT_MIN, val = 0, n = nums.size();
        int L=0, R=0;
        while(L<n && R<n) {
            val += nums[R];
            ans = max(ans, val);
            if(val<0) {
                val = 0;
                L=R+1;
                R=R+1;
            } else {
                R=R+1;
            }
        }
        return ans;
    }
        
    //Kadane's algorithm
    int maxSubArrayByKadane(vector<int>& nums) {
        int val = 0, max_val = INT_MIN;
        for(auto &i:nums) {
            val+=i;
            max_val = max(val,max_val);
            if(val<0) val = 0;
        }
        return max_val;
    }

    int maxSubArray_prefixSum_TLE(vector<int>& nums) {
        //In view of prefix sum to solve this problem
        int n = nums.size(), ans = INT_MIN;
        for(int i = 1;i<n;i++) nums[i]+=nums[i-1]; //prefix sum
        for(int i=0;i<n;i++) {
            int nums_i_1 = i==0?0:nums[i-1];
            for(int j = i;j<n;j++) {
                int sum_i_j = nums[j] - nums_i_1; //sum[i..j]
                ans = max(sum_i_j, ans);
                //printf("sum[%d..%d]=%d\n",i,j,sum_i_j );
            }
        }
        return ans;
    }

    int maxSubArray_prefixSum_improve(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN;
        for(int i = 1;i<n;i++) nums[i]+=nums[i-1]; //prefix sum
        for(int i=0;i<n;i++) {
            int nums_i_1 = i==0?0:nums[i-1];
            int j=i;//added line for improve prefix sum
            for(;j<n;j++) {
                int sum_i_j = nums[j] - nums_i_1; //sum[i..j]
                ans = max(sum_i_j, ans);
                if(sum_i_j<0) break; // Added line for improve prefix sum
                //printf("sum[%d..%d]=%d\n",i,j,sum_i_j );
            }
            i=j; //added line for improve prefix sum
        }
        return ans;
    }    




};