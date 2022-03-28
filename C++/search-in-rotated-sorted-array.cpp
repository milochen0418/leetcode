class Solution {
    //https://leetcode.com/problems/search-in-rotated-sorted-array
public:
    int search(vector<int>& a, int t) {
        int L = 0, R = a.size() - 1;
        while(L<=R) {
            int M = L + (R-L); 
            if(a[M] == t) return M;
            if(a[M]>=a[L])  //case M is in left-up raising edge
                if(a[L]<=t && t<=a[M]) 
                    return binSearch(L,M-1,t,a);
                else 
                    L = M+1;
            else //case M is in bottom-down raising edge
                if(a[M]<=t && t<=a[R]) 
                    return binSearch(M+1,R,t,a);
                else 
                    R = M-1;
        }
        return -1;
    }
        
    int binSearch(int L, int R, int t, vector<int>& a) {
        while(L<=R) {
            int M = L + (R-L); // (L+H)/2;
            if(t<a[M]) 
                R = M-1;
            else if(t>a[M]) 
                L = M+1;
            else 
                return M;
        }
        return -1;        
    }
    
    
    int rotSearch(int L, int R, int t, vector<int>& a) {
        if (L > R) return -1;
        int M = L + (R-L)/2; 
        if (a[M] == t) return M;
        if (a[L] <= a[M] ) {
            //case M is in left-up raising edge
            if (a[L] <= t && t <= a[M]) {
                return binSearch(L, M - 1, t,a);
            } else {
                return rotSearch(M + 1, R, t,a);  
            }
        } else {
            //case M is in bottom-down raising edge
            if (a[M] <= t && t <= a[R]) {
                return binSearch(M + 1, R, t,a);
            } else {
                return rotSearch(L, M - 1, t,a);
            }                
        }
    }    
};