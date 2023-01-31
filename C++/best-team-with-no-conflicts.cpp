class Solution {
    //https://leetcode.com/problems/best-team-with-no-conflicts
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        /*
        [2,1,2,1]
        [4,5,6,5]
        Sort to
        [2,2,1,1]
        [6,4,5,5]
        backtracking is choose or not choose 
        
        [1,1,2,2]
        [5,5,4,6]
        
        [2,1,1,2]
         6,5,5,4
        
        */
        
        //vector<vector<int>> v={scores, ages};
        int n = scores.size();        
        vector<vector<int>> v = vector<vector<int>>(n, vector<int>(2,0));
        for(int i =0;i<n;i++) {
            v[i][0] = scores[i];
            v[i][1] = ages[i];
        }

        sort(v.begin(), v.end(), [](auto &lhs, auto &rhs){
            return lhs[1]==rhs[1]?lhs[0]>rhs[0]:lhs[1]>rhs[1];
        });
        
        function<int(int,int)> sol = [&](int L, int R){
            int score = L<0?INT_MIN:v[L][0];
            int age = L<0?0:v[L][1];
            //printf("s,a,i=%d,%d,%d\n",score,age,i);
            if(R>=n) {
                return 0;
            }
            if(v[R][1]<age && v[R][0]>score) {
                return sol(L, R+1);
            } else {
                int val1 = v[R][0]+sol(R,R+1);
                int val2 = sol(L, R+1);
                return max(val1,val2);
            }
        };
        //return sol(INT_MIN,0,0);
        return sol(-1,0);
    }
};