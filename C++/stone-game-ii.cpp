class Solution {
    vector<vector<int>> dp;
    //refer from https://leetcode.com/problems/stone-game-ii/discuss/1708282/C%2B%2B-Simple-Intuitive-Solution-W-Explanation-or-DP-or-Memorization
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
            
        dp.resize(101, vector<int>(202)); 
		
        int sum = accumulate(piles.begin(), piles.end(), 0), diff = solve(piles, 0, 1); //sum of stones in all piles
        
        return (sum + diff)/2; //Max stones won by Alice - We need to maximize the diff so this can be maximum
    }
    
    int solve(vector<int> piles, int i, int M){
        if(i >= piles.size()) return 0; //If i>n-1 return 0
        
        if(dp[i][M] != 0) return dp[i][M]; //memorized value
        
        int total = 0, ans = INT_MIN; //total stores the total no. of stones won by Alice so far
		//ans - stores the maximum difference between Alice & Bob's stones
        
        for(int j=0; j<2*M; j++){   //1<=X<=2*M
            if(i+j < piles.size()) total += piles[i+j]; //Each time we're incrementing X, add that index's stones to total
            
            ans = max(ans, total-solve(piles, i+j+1, max(M, j+1))); //total-solve() is to check if we can maximize the score diff by incrementing X at any time.
        }     
        return dp[i][M] = ans; //return the maximum diff
    }    
};