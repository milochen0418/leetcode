class Solution {
    //https://leetcode.com/problems/diet-plan-performance
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {        
        int ans =0,n = calories.size();
        for (int i = 1;i<n;i++) 
            calories[i]+=calories[i-1];
        for(int i = 0;i<n-k+1;i++) {
            int calories_i_1 = i-1>=0?calories[i-1]:0;
            int v = calories[i+k-1] - calories_i_1;
            if(v<lower) ans--;
            if(v>upper) ans++;
        }
        return ans;
    }       
};