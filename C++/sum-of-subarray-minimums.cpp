class Solution {
    //https://leetcode.com/problems/sum-of-subarray-minimums/
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9+7;
        int n = arr.size();
        int ans = 0;
        
        vector<vector<int>> A = vector<vector<int>>(n,vector<int>(5,0)); 
        for(int i = 0; i<n;i++) {
            int L=i, R=i;
            for(; L>=0;L--) {
                if(arr[L] < arr[i]) break;
            }
            for(; R<n;R++) {
                if(arr[R] < arr[i]) break;
            }
            //This is (L .. R), but not [L .. R]
            A[i][0] = L;
            A[i][1] = R;
            A[i][2] = R-L-1;
            A[i][3] = (R-i) * (i-L);
            A[i][4] = arr[i] * (R-i) * (i-L);
            //ans= ((ans%mod) + (A[i][2]%mod)) %mod;
            ans+=A[i][4];
        }
        
        for(int i = 0; i <A.size();i++) {
            printf("(L,R,cnt) = (%d, %d, %d)\n", A[i][0], A[i][1], A[i][2] );
        }
        return ans; 
    }  
    /*
    [3,2,5,1,4,2]
    Output 32, Expected 32
    [3,2,5,4,2]
    Output 34 
    Expected 38 
    because [3,2,5,4,2],  [2,5,4,2] is not coounted in this code.
    [ ... min ... min ...] is missing to counted. 
    */
};