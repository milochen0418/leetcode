class Solution {
    //https://leetcode.com/problems/max-consecutive-ones-ii
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        return answer2(a);
        int n = a.size(), ans = INT_MIN;
        for(int i = 1; i<n; i++) if(a[i]!=0) a[i]=a[i-1]+a[i];
        for(int i = n-2;i>=0;i--) if(a[i]>0 && a[i+1]>0) a[i]=a[i+1];
        //Input [1,0,1,1,1,0,0,1,1,0] -> [1,0,3,3,3,0,0,2,2,0] here
        
        //convert [1,0,3,3,3,0,0,2,2,0]
        //  into  [1,4,3,3,3,4,3,2,2,3]
        //and then, select the maximum
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
    
    int answer2(vector<int>& a) {
        int zeros=0, ans=0, L=0, R=0, n=a.size();
        while(R<n) {            
            if(zeros>1) {
                zeros-=(a[L]==0);
                L++;
            } else {
                zeros+=(a[R]==0);
                if(zeros<=1)ans = max(ans,R-L+1);
                R++;
            }
        }
        return ans;
    }
};