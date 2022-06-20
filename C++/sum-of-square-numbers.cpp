class Solution {
    //https://leetcode.com/problems/sum-of-square-numbers
public:
    bool judgeSquareSum(int c2) { //N*logN
        using ll = long long;
        int rootC = sqrt(c2);
        for(int i=0; i<=rootC;i++) {            
            ll L=0,R=(ll)rootC;
            ll t = (ll)c2-(ll)i*(ll)i;
            while(L<=R) {
                ll M = L+(R-L)/2;
                if(M*M == t) return true;
                if(M*M<t) L=M+1; else R=M-1;                
            }
        }
        return false;
    }

    bool judgeSquareSumBruteForce(int c2) { //O(N^2)
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