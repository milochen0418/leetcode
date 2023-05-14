class Solution {
    //https://leetcode.com/problems/find-the-losers-of-the-circular-game/
public:
    vector<int> circularGameLosers(int n, int k) {
        /*[3,4]  is ans */
        unordered_set<int> winner;
        int p = 0;
        int i = 1;
        while( winner.find(p) == winner.end()) {
            winner.insert(p);    
            p = (p + k*i)%n;
            i++;
        }        
        vector<int> ans;
        for(int i = 0; i < n;i++) 
            if(winner.find(i) == winner.end())
                ans.push_back(i+1);
        return ans;
    }
};