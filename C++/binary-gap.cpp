class Solution {
    //https://leetcode.com/problems/binary-gap
    //article https://leetcode.com/problems/binary-gap/discuss/3081503/C%2B%2B-One-Pass-O(logN)-6-lines
public:
    int binaryGap(int n) {
        int L =-1,R=-1,cnt=0, ans=0;
        while(n>0) {
            if(n%2==1) {
                L=R;
                R=cnt;
                if(L!=-1 && R!=-1) 
                    ans = max(ans,R-L);
            }
            n/=2;
            cnt++;
        }
        return ans;
    }
};