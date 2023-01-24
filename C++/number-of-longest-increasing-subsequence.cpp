class Solution {
    //https://leetcode.com/problems/number-of-longest-increasing-subsequence
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> allpath;
        vector<int> stk;
        function<void(int)> dfs = [&](int i){
            stk.push_back(nums[i]);
            int is_no_leaf = 1;
            for(int j = i+1;j<n;j++) {
                if(nums[j]>stk.back()) {
                    dfs(j);   
                    is_no_leaf = 0;
                }
            }
            if(is_no_leaf) {
                allpath.push_back(stk);
            }
            stk.pop_back();
        };
        for(int i = 0;i<nums.size();i++) dfs(i);
        /*
        for(auto &path:allpath) {
            for(auto &i:path) printf("%d,", i);
            printf("\n");
        }*/
        int ans = 0;
        int maxlen = 0;
        for(auto &path:allpath) maxlen = max(maxlen, (int)path.size());
        for(auto &path:allpath) if(maxlen == (int)path.size())ans++;
        return ans;
    }
};