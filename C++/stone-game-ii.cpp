class Solution {
    vector<vector<int>> dp;
    vector<int>* piles=nullptr;
    //refer from https://leetcode.com/problems/stone-game-ii/discuss/1708282/C%2B%2B-Simple-Intuitive-Solution-W-Explanation-or-DP-or-Memorization
public:
    int stoneGameII(vector<int> &ps) {
        piles = &ps;
        int n = piles->size();
            
        dp.resize(n+1, vector<int>(n+1)); 
		
        int sum = accumulate(piles->begin(), piles->end(), 0), diff = solve(0, 1); //sum of stones in all piles
        
        return (sum + diff)/2; //Max stones won by Alice - We need to maximize the diff so this can be maximum
    }
    
    int solve(int i, int M){
        if(i >= piles->size()) return 0; //If i>n-1 return 0
        
        if(dp[i][M] != 0) return dp[i][M]; //memorized value
        
        int my_taken_in_turn = 0, ans = INT_MIN; //total stores the total no. of stones won by Alice so far
		//ans - stores the maximum difference between Alice & Bob's stones
        
        for(int j=0; j<2*M; j++){   //1<=X<=2*M
            if(i+j < piles->size()) my_taken_in_turn += (*piles)[i+j]; //Each time we're incrementing X, add that index's stones to total
            int your_optimal_number_more_than_mine = solve(i+j+1, max(M, min(j+1,(int)piles->size()) ));
            ans = max(ans, my_taken_in_turn-your_optimal_number_more_than_mine); //total-solve() is to check if we can maximize the score diff by incrementing X at any time.
        }     
        return dp[i][M] = ans; //return the maximum diff
    }    
};