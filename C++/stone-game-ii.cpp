class Solution {
    vector<vector<int>> dp;
public:
    int stoneGameII(vector<int> &piles) {
        
        int n = piles.size();
        dp.resize(n+1, vector<int>(n+1)); 
        int total = accumulate(piles.begin(), piles.end(), 0);
        int diff = more_than_yours(piles, 0, 1); 
        return (total + diff)/2; 
    }
    
    int more_than_yours(vector<int> &piles, int i, int M){
        if(i >= piles.size()) return 0; 
        if(dp[i][M] != 0) return dp[i][M]; 
        int my_taken_in_turn = 0;
        int max_more_than_yours = INT_MIN; 
        
        for(int j=0; j<2*M; j++){   //1<=X<=2*M
            if(i+j < piles.size()) my_taken_in_turn += piles[i+j]; 
            int competitor_more_than_mine = more_than_yours(piles, i+j+1,  max(M, min(j+1, (int)piles.size())) );
            max_more_than_yours = max(max_more_than_yours, my_taken_in_turn - competitor_more_than_mine);
        }     
        return dp[i][M] = max_more_than_yours;
    }    
};