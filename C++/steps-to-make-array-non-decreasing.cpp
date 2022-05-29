class Solution {
    //https://leetcode.com/problems/steps-to-make-array-non-decreasing/
public:
    int totalSteps(vector<int>& a) {
        a.push_back(INT_MAX);
        int n = a.size(), ans = 0;
        int j = 0;
        
        for(int i = 1; i<n;i++) {
            if(a[i]>=a[j]) {
                int cnt = 0;
                for(int k = i-1;k>j;k--) {
                    printf("%d ", a[k]);
                    if(k==i-1) {
                        cnt++;
                    } else {
                        if(a[k] <= a[k+1]) cnt++;
                    }
                }
                printf(" cnt =%d\n",cnt);
                ans = max(ans, cnt);
                j = i;
            }
            //My failed test-case
            //[10,1,2,3,4,5,6,1,2,3]
            //(1) 10,x,2,3,4,5,6,x,2,3  
            //(2) 10,x,3,4,5,6,x,3  
            //(3) 10,x,4,5,6,x
            //(4) 10,x,5,6
            //(5) 10,x,6
            //(6) 10,x
        }
        return ans;
    }
};

/* test-case
[5,14,15,2,11,5,13,15]
[5,3,4,4,7,3,6,11,8,5,11]
[10,1,2,3,4,5,6,1,2,3]
[4,5,7,7,13]
*/