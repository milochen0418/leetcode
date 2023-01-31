class Solution {
    //https://leetcode.com/problems/best-team-with-no-conflicts
    //article https://leetcode.com/problems/best-team-with-no-conflicts/discuss/3123875/C%2B%2B-DP-solution-similar-to-House-Robber
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        //Dynamic Programming from bestTeamScore_TLE_v02() 
        //because the range of L and R only about in 0~1000
        int n = scores.size();        
        vector<vector<int>> v = vector<vector<int>>(n, vector<int>(2,0));
        for(int i =0;i<n;i++) {
            v[i][0] = scores[i];
            v[i][1] = ages[i];
        }

        sort(v.begin(), v.end(), [](auto &lhs, auto &rhs){
            return lhs[1]==rhs[1]?lhs[0]>rhs[0]:lhs[1]>rhs[1];
        });
        
        vector<vector<int>> dp = vector<vector<int>>(n+2, vector<int>(n+1,-1));
        function<int(int,int)> sol = [&](int L, int R){
            if(R>=n) return 0;
            if(dp[L+1][R]!=-1) return dp[L+1][R];
            
            int score = L<0?INT_MIN:v[L][0];
            int age = L<0?0:v[L][1];
            if(v[R][1]<age && v[R][0]>score) {
                return dp[L+1][R] = sol(L, R+1);
            } else {
                int val1 = v[R][0]+sol(R,R+1);
                int val2 = sol(L, R+1);
                return dp[L+1][R] = max(val1,val2);
            }
        };
        //return sol(INT_MIN,0,0);
        return sol(-1,0);
    }

    int bestTeamScore_TLE_v02(vector<int>& scores, vector<int>& ages) {
        //Compare to bestTeamScore_TLE_v01
        //Use (L,R) to instead (score,age,i).. the R is mean i but score=v[L], age=v[L]
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

    int bestTeamScore_TLE_v01(vector<int>& scores, vector<int>& ages) {
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
        
        function<int(int,int,int)> sol = [&](int score, int age, int i){
            //printf("s,a,i=%d,%d,%d\n",score,age,i);
            if(i>=n) {
                //printf("case1\n");
                return 0;
            }
            if(v[i][1]<age && v[i][0]>score) {
                //printf("case2\n");
                return sol(score, age, i+1);
            } else {
                int val1 = v[i][0]+sol(v[i][0],v[i][1],i+1);
                int val2 = sol(score, age, i+1);
                return max(val1,val2);
            }
        };
        return sol(INT_MIN,0,0);
    }    
};