class Solution {
    //https://leetcode.com/problems/stone-game-iii/
public:
    string stoneGameIII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp = vector(n+1, vector<int>(n+1,0));
        int g = more_than_yours(piles, dp);
        return "Bob";
    }
    int more_than_yours(vector<int>& piles, vector<vector<int>> & dp) {
        return 5;
    }
};