class Solution {
    //https://leetcode.com/problems/sum-of-square-numbers
public:
    bool judgeSquareSum(int c2) {
        using ll = long long;
        int rootC = sqrt(c2);
        //printf("rootC=%d\n",rootC);
        for(int i=0; i<=rootC;i++) {
            for(int j=0;j<=rootC;j++) {
                //printf("i=%d,j=%d, i^2+j^2=%d\n",i,j ,(i*i+j*j));
                if( ((ll)i*(ll)i+(ll)j*(ll)j)==(ll)c2) {
                    return true;
                }
            }
        }
        return false;
    }
};