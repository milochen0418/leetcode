class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        vector<int>& A = arr;
        int n = A.size();
        for(int i = 1;i<n;i++) A[i]+=A[i-1];
        //presum of [0..L] = A[L]
        //presum of [i..j] = A[j]-A[i-1];  
        //presum of [R..n-1] =A[n-1]-A[R];
        for(int L=1;L<n-1;L++) {
            for(int R=L;R<n-1;R++){
                int left = A[L-1];
                int center = A[R]-A[L-1];
                int right = A[n-1]-A[R];
                //printf("L,R,left,center,right = %d,%d,%d,%d,%d\n",L,R,left,center,right);
                if(left==right && center==left) return true;
            }
        }
        return false;
    }
};