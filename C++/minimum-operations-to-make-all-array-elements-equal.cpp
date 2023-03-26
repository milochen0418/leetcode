class Solution {
    //https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/
public:
    /*
    
    [3,1,6,8] -> sort [1,3,6,8]
    [1,  3]  5  [ 6,  8]
    5-1 5-2      5+1 5+3 
    
    Right part sum[6,8] - 5*2 = 4
    Left part 5*2- sum[1,3] = 10-4 =6


    [1,  3]  3  [ 6,  8]
    3-1 3-3      3+3 3+5 
    left part  3*2 - sum[0..1] = 6 - 4 = 2
    right part sum[2..3] - 3*2 = 14 -6 = 8

    So we want to find I s.t. A[I-1] <= t <A[I]

    A= [1,3,6,8]
    S= [0,1,4,10,18]
    A.sum[0..2] = S[3]
    A.sum[0..3] = S[4]
    A.sum[1..2] = S[3]-S[1]
    
    => A.sum[i..j] = S[j+1] - S[i]
    
    
    
    
    */
    typedef long long ll;
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        
        printf("\n");
        vector<int>& A = nums;
        //vector<ll> ans = vector<int>(queries.size(),0);
        vector<ll>ans;
        sort(A.begin(), A.end());
        /*
        printf("A=[");
        for(auto &vv: nums) 
            printf("%d, ",vv);
        printf("]\n");
        */
        vector<ll> S={0};
        for(auto &i:A) S.push_back(S.back() + (ll)i);
        /*
        printf("S=[");
        for(auto &vv: S) 
            printf("%lld, ",vv);
        printf("]\n");
        */
        for(auto &q: queries) {
            int t=q;
            int n = A.size();
            ll val = 0;
            
            if(t<A[0]) {//answer onlye care right part 
                val = S[n] - ((ll)q * (ll)n);
                ans.push_back(val);
                continue;
            } else if(t>=A[n-1]) {//answer only care left part
                val = ((ll)q*(ll)n )-S[n];
                ans.push_back(val);
                continue;
            }
            
            //int L = 0, R=n-1;
            int L = 0, R=A.size()-1;
            int I = -1; 
            //printf("binary search \n");
            while(L<=R){
                int M = L+(R-L)/2;
                //printf("[%d,%d] -> %d\n,",L,R,M);
                if(A[R]<=t) {
                    I=R;
                    break;
                }
                
                if( (A[M] <= t) && (M+1>=n || t < A[M+1])) {
                    I = M;
                    //printf("select %d,\n",M);
                    break;
                }
                if(A[M]<=t) { //A[M+1]<=t
                    L=M+1;
                } else {
                    R=M-1;
                }
                
            }
            printf("\n");
            if(I==-1) {
                ans.push_back(-1);
                continue;
            }
            
            ll left_part=0, right_part = 0;
            ll Lqmul = ((ll)q*(ll)(I+1)), Lsum = (S[I+1]-S[0]);
            ll Rqmul = ((ll)q*(ll)(n-(I+1))), Rsum = (S[n]-S[I+1]);
            left_part = Lqmul - Lsum;
            right_part = Rsum - Rqmul;
            /*
            printf("q = %ld, I=%d\n", q,I);
            printf("left_part = Lqmul:%ld - Lsum:%ld = %ld\n", Lqmul ,Lsum, Lqmul-Lsum);
            printf("right_part = Rsum:%ld - Rqmul:%ld = %ld\n", Rsum ,Rqmul ,  Rsum - Rqmul);
            */
            val = left_part+right_part;
            ans.push_back(val);
        }
        return ans;
    }
    
};