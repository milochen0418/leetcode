class Solution {
    //https://leetcode.com/problems/daily-temperatures
public:
    /*
    [73,74,75,71,69,72,76,73]
    [ 1, 1, 4, 2, 1, 1, 0, 0]
    */
    vector<int> dailyTemperatures(vector<int>& temperatures) {        
        int n = temperatures.size();
        vector<int> &A = temperatures, ans=vector<int>(n,0);
        for(int i = 0; i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(A[j]>A[i]) {
                    ans[i]=j-i;
                    break;
                }
            }
        }
        return ans;
    }
};