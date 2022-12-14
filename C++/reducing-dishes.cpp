class Solution {
    //https://leetcode.com/problems/reducing-dishes/
    //article https://leetcode.com/problems/reducing-dishes/discuss/2911044/C%2B%2B-or-Prefix-Sum-or-Easy
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        vector<int>& A = satisfaction;
        int n = A.size(), ans = 0;
        sort(A.begin(), A.end(), greater<int>());
        for(int i = 1; i<n;i++) A[i] = A[i] + A[i-1];
        for(int i = 1; i<n;i++) A[i] = A[i] + A[i-1];
        for(int i = 0; i<n;i++) ans = max(ans, A[i]);
        return ans;
    }
};