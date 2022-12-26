class Solution {
    //https://leetcode.com/problems/minimum-cost-to-connect-sticks/
public:
    int connectSticks(vector<int>& sticks) {
        vector<int>& A = sticks;
        int ans=0;
        while(A.size()>1) {
            sort(A.begin(), A.end(),greater<int>());
            A[A.size()-2] += A.back();
            ans+=A[A.size()-2];
            A.pop_back();
        }
        return ans;
    }
};