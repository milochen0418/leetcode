class Solution {
    //https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game
    //article: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/discuss/3032978/C%2B%2B-One-Pass
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> rmp = vector<vector<int>>(2, vector<int>(3,0));//column check
        vector<vector<int>> cmp = vector<vector<int>>(2, vector<int>(3,0));//row check
        vector<vector<int>> dmp = vector<vector<int>>(2, vector<int>(2,0));//diagonal check
        
        for(int i = 0;i<moves.size();i++) {
            vector<int>& rc = moves[i];
            int &r = rmp[i%2][rc[0]];
            int &c = cmp[i%2][rc[1]]; 
            vector<int> &d = dmp[i%2];
            r++,c++;
            
            if(rc[0]==rc[1])d[0]++;
            if(rc[0]+rc[1]==2)d[1]++;
            if(r>=3 || c>=3) return i%2==0?"A":"B";
            if(d[0]>=3 || d[1]>=3) return i%2==0?"A":"B";
        }
        return moves.size()>=9?"Draw":"Pending";
    }
};