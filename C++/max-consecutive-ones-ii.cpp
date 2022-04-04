class Solution {
    //https://leetcode.com/problems/max-consecutive-ones-ii
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int n = a.size(), ans = INT_MIN;
        for(int i = 1; i<n; i++) if(a[i]!=0) a[i]=a[i-1]+a[i];
        for(int i = n-2;i>=0;i--) if(a[i]>0 && a[i+1]>0) a[i]=a[i+1];
        for(int i=0;i<n;i++) {
            if(a[i]!=0){
                ans = max(ans, a[i]);
            } else {
                int L = (i-1)<0?0:a[i-1];
                int R = (i+1)>=n?0:a[i+1];
                ans = max(ans, 1+L+R);
            }
        }
        return ans;
    }
};