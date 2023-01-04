class Solution {
    //https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times
public:
    #define printf(...) empty_printf(__VA_ARGS__)
    #define empty_printf(...)
    
    //O(N*M*K)
    bool containsPattern(vector<int>& arr, int m, int k) {
        for(int i = 0; i<arr.size();i++) 
            if(is_pattern(arr,m,k,i)) return true;
        return false;
    
    }
    bool is_pattern(vector<int>& A, int m, int k, int start) {
        int n = A.size();
        if(start+m*k>n) {
            printf("Early Leave\n");
            printf("start,m,k,n=%d,%d,%d,%d\n",start,m,k,n);
            printf("start+m*k = %d\n",start+m*k);
            return false;
        }
        for(int j = 0;j<m;j++)
            for(int i = 1;i<k;i++)
                if( A[start + i*m+j] != A[start + j]) {
                    printf("start,i,j,m = %d, %d, %d, %d\n",start,i,j,m);
                    printf("start + i*m+j = %d\n", start + i*m+j);
                    printf("start + j = %d\n", start+j);
                    return false;
                }
        return true;
    }
};