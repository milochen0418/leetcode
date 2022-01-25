class Solution {
    //https://leetcode.com/problems/stone-game-iii/
    //My Article https://leetcode.com/problems/stone-game-iii/discuss/1718806/stone-game-iii-or-C%2B%2B-or-DP-or-Top-Down-or-easy
public:
    string stoneGameIII(vector<int>& piles) {
        int n = piles.size();
        
        vector<int> dp = vector<int>(n+1, INT_MIN);
        int alice_more_score = more_than_yours(piles, dp, 0);
        if(alice_more_score==0) return "Tie";
        if(alice_more_score>0) return "Alice";
        return "Bob";
    }
    int more_than_yours(vector<int>& piles, vector<int>& dp, int i) {
        if(dp[i] != INT_MIN) return dp[i];
        if(i >= piles.size()) return dp[i] = 0;
        
        int my_taken = 0, max_more = INT_MIN;
        for(int X=i; X<i+3 && X < piles.size(); X++) {
            my_taken += piles[X];
            int competitor_more_then_mine = more_than_yours(piles, dp, X+1);
            int the_more = my_taken - competitor_more_then_mine;
            max_more = max(max_more, the_more);
        }
        return dp[i]=max_more;
    }
};