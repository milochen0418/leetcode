class Solution {
    //https://leetcode.com/problems/special-permutations/
public:
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> dp = vector<int>(1<<n, -1);
        function<int(int, int)> sol = [&](int mask, int val) {
            int sum = 0;
            if (mask  == (1<<n)-1) {
                sum = 1;
            } else {
                for(int i = 0; i<n;i++) {
                    if( (1<<i) & mask ) continue;
                    if(nums[i] % val == 0 || val % nums[i] == 0) {
                        sum+=sol(mask|(1<<i), nums[i]);
                    }
                }
            }
            return sum;
        };
        for(int i = 0; i<n;i++) {
            int mask = 1<<i;
            ans+=sol(mask, nums[i]);
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