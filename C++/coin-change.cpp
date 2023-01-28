class Solution {
    //https://leetcode.com/problems/coin-change
    //article https://leetcode.com/problems/coin-change/discuss/2068212/C%2B%2B-or-Dynamic-Programming-(Top-Down)
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5348544365168011/
public:
    int coinChange(vector<int>& coins, int amount) {
        typedef long long ll;
        const ll VAL_MAX=(((ll)INT_MAX)*(ll)2);
        ll n = amount;                       
        if(n == 0) return 0;
        
        vector<ll> dp = vector<ll>(n+1,-1);
        dp[n] = 0;//mean achive
        function<ll(ll)> sol = [&](ll i){
            if(i>n) return VAL_MAX;
            if(dp[i]!=-1) return dp[i];
            ll minv = VAL_MAX;
            for(int j = 0;j<coins.size();j++) {
                minv = min(minv, sol(i+coins[j]));
            }
            if(minv >= VAL_MAX) return dp[i] = VAL_MAX;
            return dp[i] = 1+minv;
        };
        ll ans = sol(0);
        if(ans>=VAL_MAX) return -1;
        return (int)ans;
    }
    
    int coinChange_v01(vector<int>& coins, int amount) {
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