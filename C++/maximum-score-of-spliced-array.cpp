class Solution {
    //https://leetcode.com/problems/maximum-score-of-spliced-array
    //article https://leetcode.com/problems/maximum-score-of-spliced-array/discuss/2199344/C%2B%2B-or-greedy-approach-O(n)-or-observation-and-explanation
public:
    int maximumsSplicedArray(vector<int>& a1, vector<int>& a2) {
        //Observation 
        /*
            a1 =  [20,40,20,70,30], pre1 = [20,60,80,150,180]
            a2 =  [50,20,50,40,20], pre2 = [50,70,120,160,180]
            sum(a1[3..4]) = pre1[4] - pre1[2]
            sum(a2[3..4]) = pre2[4] - pre1[2]
            sum(ax[L..R]) = prex[R] - prex[L-1]  when prex[-1] = 0
            
        */
        
        int n = a1.size();
        
        /* Brute Force solution but Time Limited Exceeded
        for(int i = 0; i<n;i++) {
            int a1i_1 = i==0?0:a1[i-1];
            a1[i] += a1i_1;
        }
        for(int i = 0; i<n;i++) {
            int a2i_1 = i==0?0:a2[i-1];
            a2[i] += a2i_1;
        }
        //for(int i = 0;i<n;i++) {printf("%d, ",a1[i]);} printf("\n");
        
        int ans = max(a1[n-1],a2[n-1]);
        for(int L=0;L<n;L++) {
            for(int R=L;R<n;R++) {
                int sub1 = a1[R]-(L==0?0:a1[L-1]);
                int sub2 = a2[R]-(L==0?0:a2[L-1]);
                int candidate = max(a1[n-1]-sub1+sub2, a2[n-1]-sub2+sub1);
                ans = max(ans, candidate);
            }
        }
        return ans;
        */
        
        /*180+40
            my test case
            a1 =  [50,20,50,40,20], sum1 = 180, max_inc1=(70+30)-(40+20) = 40  ... ans = 180+40
            a2 =  [20,40,20,70,30], sum2 = 180, max_inc2=? 
        */
        int L,R, acc1, acc2;
        int sum1=0,sum2=0;
        int max_inc1=0, max_inc2;
        for(int i = 0;i<n;i++) {
            sum1 +=a1[i];
            sum2 +=a2[i];
        }
        
        //Assume maximum is happened in a1. 
        L=0; R=0;
        acc1 = 0; acc2 =0;
        max_inc1=0;
        while(L<n && R<n) {
            acc1 += a1[R];
            acc2 += a2[R];
            max_inc1 = max(max_inc1, acc2-acc1);
            if(acc1>=acc2) {
                L=R+1;
                R=L;
                acc1=0;
                acc2=0;
            } else {
                R=R+1;
            }
        }
        //return max_inc1+ sum1;
        
        
        //Assume maximum is happened in a2        
        L=0; R=0;
        acc1 = 0; acc2 =0;
        max_inc2=0;
        while(L<n && R<n) {
            acc2 += a2[R];
            acc1 += a1[R];
            max_inc2 = max(max_inc2, acc1-acc2);
            if(acc2>=acc1) {
                L=R+1;
                R=L;
                acc1=0;
                acc2=0;
            } else {
                R=R+1;
            }
        }
        return max(max_inc1 + sum1, max_inc2 + sum2);
        
        
        
        //return ans;
        
        
    }
};