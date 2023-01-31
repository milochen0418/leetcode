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
        
        function<int(int,int,int)> sol = [&](int score, int age, int i){
            //printf("s,a,i=%d,%d,%d\n",score,age,i);
            if(i>=n) {
                return 0;
            }
            if(v[i][1]<age && v[i][0]>score) {
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