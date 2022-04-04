class Solution {
    //https://leetcode.com/problems/max-consecutive-ones-iii
public:
    int longestOnes(vector<int>& a, int k) {
        int zeros=0, ans=0, L=0, R=0, n=a.size();
        while(R<n) {            
            if(zeros>k) {
                zeros-=(a[L]==0);
                L++;
            } else {
                zeros+=(a[R]==0);
                if(zeros<=k)ans = max(ans,R-L+1);
                R++;
            }
        }
        return ans;
    }
};