class Solution {
    //https://leetcode.com/problems/campus-bikes-ii
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        int ans = INT_MAX;
        vector<int> A=vector<int>(m,0);
        for(int i = 0; i<m;i++) A[i] = i;
        do {
            int sum_dis = 0;
            for(int i = 0;i<n;i++) 
                sum_dis+= abs(workers[i][0] - bikes[A[i]][0]) + abs(workers[i][1]-bikes[A[i]][1]);
            ans = min(ans, sum_dis);
        } while(next_permutation(A.begin(), A.end()));        
        return ans;
    }
};