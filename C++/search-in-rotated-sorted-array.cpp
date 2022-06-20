class Solution {
    //https://leetcode.com/problems/search-in-rotated-sorted-array
public:
    int search(vector<int>& a, int t) {
        int n = a.size(), L=0, R=n-1;
        while(L<=R) {
            int M = L+(R-L)/2;
            if(a[M] == t) return M;
            if(a[M]>=a[L]) {//a[M] in left-up raising edge
                if(a[L]<=t && t<=a[M]) R=M-1; else L=M+1;
            } else { //a[M] in right-bottom raising edge
                if(a[M]<=t && t<=a[R]) L=M+1; else R=M-1;
            }
        } return -1;
    }

    int searchByCallFunc(vector<int>& a, int t) {
        int L = 0, R = a.size() - 1;
        //return recursiveSearch(L,R,t,a);
        while(L<=R) {
            int M = L + (R-L)/2; 
            if(a[M] == t) return M;
            if(a[M]>=a[L])  //case M is in left-up raising edge
                if(a[L]<=t && t<=a[M]) 
                    return iterativeBinSearch(L,M-1,t,a);
                else 
                    L = M+1;
            else //case M is in bottom-down raising edge
                if(a[M]<=t && t<=a[R]) 
                    return iterativeBinSearch(M+1,R,t,a);
                else 
                    R = M-1;
        }
        return -1;
    }
        
    int iterativeBinSearch(int L, int R, int t, vector<int>& a) {
        while(L<=R) {
            int M = L + (R-L)/2; // (L+H)/2;
            if(t<a[M]) 
                R = M-1;
            else if(t>a[M]) 
                L = M+1;
            else 
                return M;
        }
        return -1;        
    }
    
    int recursiveBinSearch(int L, int R, int t, vector<int>& a) {
        if (L > R) return -1;
        if (t < a[L] || t > a[R]) return -1;
        int M = L + (R-L) / 2;
        if (a[M] < t) return recursiveBinSearch(M + 1, R, t, a);
        if (t < a[M]) return recursiveBinSearch(L, M - 1, t, a);
        return M; // case  (a[M] == t)
    }    
    
    
    int recursiveSearch(int L, int R, int t, vector<int>& a) {
        if (L > R) return -1;
        int M = L + (R-L)/2; 
        if (a[M] == t) return M;
        if (a[L] <= a[M] ) //case M is in left-up raising edge
            if (a[L] <= t && t <= a[M]) 
                return recursiveBinSearch(L, M - 1, t,a);
            else 
                return recursiveSearch(M + 1, R, t,a);  
        else //case M is in bottom-down raising edge 
            if (a[M] <= t && t <= a[R]) 
                return recursiveBinSearch(M + 1, R, t,a);
            else 
                return recursiveSearch(L, M - 1, t,a);            
    }
};