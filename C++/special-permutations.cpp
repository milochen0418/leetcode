class Solution {
    //https://leetcode.com/problems/special-permutations/
public:
    int specialPerm(vector<int>& nums) {
        int mod = 1e9+7;
        int n = nums.size();
        int ans = 0;
        vector<vector<int>> dp = vector<vector<int>>(1<<n, vector<int>(n,-1));
        function<int(int, int)> sol = [&](int mask, int idx) {
            if(dp[mask][idx] != -1) return dp[mask][idx];
            int val = nums[idx];
            int sum = 0;
            if (mask  == (1<<n)-1) {
                sum = 1;
            } else {
                for(int i = 0; i<n;i++) {
                    if( (1<<i) & mask ) continue;
                    if(nums[i] % val == 0 || val % nums[i] == 0) {
                        sum = sum + sol(mask|(1<<i),i);
                        sum = sum % mod;
                    }
                }
            }
            return dp[mask][idx] = sum;
        };
        for(int i = 0; i<n;i++) {
            int mask = 1<<i;
            ans = ans +  sol(mask, i);
            ans = ans % mod;
        }
        return ans;
    }

    int specialPerm_v02(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        function<int(int, int)> sol = [&](int mask, int idx) {
            int val = nums[idx];
            int sum = 0;
            if (mask  == (1<<n)-1) {
                sum = 1;
            } else {
                for(int i = 0; i<n;i++) {
                    if( (1<<i) & mask ) continue;
                    if(nums[i] % val == 0 || val % nums[i] == 0) {
                        sum+=sol(mask|(1<<i), i);
                    }
                }
            }
            return sum;
        };
        for(int i = 0; i<n;i++) {
            int mask = 1<<i;
            ans+=sol(mask, i);
        }
        return ans;
    }

    int specialPerm_v01(vector<int>& nums) {
        int n = nums.size();
        int ans = 0; 
        function<void(int, int)> sol = [&](int mask, int val){
            if (mask  == (1<<n)-1) {
                ans++;
                return; 
            }
            for(int i = 0; i<n;i++) {
                if( (1<<i) & mask ) continue;
                if(nums[i] % val == 0 || val % nums[i] == 0) {
                    sol(mask|(1<<i), nums[i]);
                }
            }
        };
        
        for(int i = 0; i<n;i++) {
            int mask = 1<<i;
            sol(mask, nums[i]);
        }
        
        return ans;
    }
};