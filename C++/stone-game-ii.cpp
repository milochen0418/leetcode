class Solution {
    //Facebook explain in detail with Chinese https://www.facebook.com/groups/1451299754892511/posts/4996360167053101/
    //My Article https://leetcode.com/problems/stone-game-ii/discuss/1716199/C%2B%2B-or-DP-or-stone-game-ii
public:
    int stoneGameII(vector<int> &piles) {
        int n = piles.size();
        vector<vector<int>> dp = vector<vector<int>>(n+1, vector<int>(n+1,0));
        int total = accumulate(piles.begin(), piles.end(), 0);
        int diff = more_than_yours(piles, dp, 0, 1); 
        return (total + diff)/2; 
    }
    
    int more_than_yours(vector<int> &piles, vector<vector<int>> &dp, int i, int M){
        M = M>piles.size()?piles.size():M;
        if(i >= piles.size()) return 0; 
        if(dp[i][M] != 0) return dp[i][M]; 
        int my_taken_in_turn = 0;
        int max_more_than_yours = INT_MIN; 
        
        for(int X=1; X<=2*M; X++) {
            if(i-1+X < piles.size()) my_taken_in_turn += piles[i-1+X]; 
            int competitor_more_than_mine = more_than_yours(piles, dp, i+X,  max(M,X));
            max_more_than_yours = max(max_more_than_yours, my_taken_in_turn - competitor_more_than_mine);
        }     
        return dp[i][M] = max_more_than_yours;
    }    
};