class Solution {
    //https://leetcode.com/problems/count-increasing-quadruplets/
public:
    typedef long long ll;
    long long countQuadruplets(vector<int>& nums) {
        /*
        Observation. 
        
        0<= h<i<j<k <n
        nums[h]<nums[j]<nums[i]<nums[k]
        
        That's we can find all pair i<j (i,j) s.t. nums[i]>nums[j] by O(N^2) first 
        by the 2-level loop. 
        
        After we find out nums[i]>nums[j]...
        We need find the elements e_h in nums[0 .. i-1] s.t. e_h < nums[j]
        We need find the elements e_k in nums[j+1..n-1] s.t. e_k > nums[i]

        This observation is contributed by ZZZ, 哎呀呀 in LeetCode Contest After Party
        */
        int n = nums.size();
        vector<vector<int>> h_cnt = vector<vector<int>>(n, vector<int>(n,0));
        vector<vector<int>> k_cnt = vector<vector<int>>(n, vector<int>(n,0));

        for(int j=2;j<n-1;j++){
            int max_i = j-1;
            for(int h =0;h<max_i;h++) {
                int h_cnt_minus = h-1<0?0:h_cnt[j][h-1];
                h_cnt[j][h] =  h_cnt_minus + (nums[h]<nums[j]);
            }
        }

        for(int i=1;i<n-2;i++) {
            int min_j = i+1;
            for(int k=n-1;k>min_j;k--){
                int k_cnt_plus = k+1>=n?0:k_cnt[i][k+1];
                k_cnt[i][k] = k_cnt_plus + (nums[k]>nums[i]);
            }
        }
        ll ans = 0;
        for(int i=1;i<n-2;i++) {
            for(int j=i+1;j<n-1;j++) {
                if(nums[i]>nums[j]) {
                    ans += (ll)h_cnt[j][i-1]*(ll)k_cnt[i][j+1];
                }
            }
        }
        return ans;
    }
};