class Solution {
    //https://leetcode.com/problems/coin-change
    //article https://leetcode.com/problems/coin-change/discuss/2068212/C%2B%2B-or-Dynamic-Programming-(Top-Down)
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5348544365168011/
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp= vector<int>(amount+1, -2);
        dp[0] = 0;
        return sol(amount, coins, dp);
    }
    int sol(int val , vector<int>& coins, vector<int>&dp ){
        if(val<0) return -1;
        if(dp[val] > -2) return dp[val];
        
        int min_val = INT_MAX;
        for(auto& c:coins) {
            int can = sol(val-c, coins, dp);
            if(can>=0) min_val = min(min_val, can);
        }
        if(min_val == INT_MAX)  {
            dp[val] = -1;
        } else {
            dp[val] = 1+min_val;
        }
        return dp[val];
    }    
};