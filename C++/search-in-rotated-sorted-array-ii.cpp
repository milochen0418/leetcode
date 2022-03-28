class Solution {
    //https://leetcode.com/problems/search-in-rotated-sorted-array-ii
public:
    bool search(vector<int>& a, int t) {
        int L = 0, R = a.size() - 1;
        while(L<=R) {            
            int M = L + (R-L)/2; 
            if(a[M] == t) return true;
            
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
        return false;
    }
        
    bool iterativeBinSearch(int L, int R, int t, vector<int>& a) {
        while(L<=R) {
            int M = L + (R-L)/2; // (L+H)/2;
            if(t<a[M]) 
                R = M-1;
            else if(t>a[M]) 
                L = M+1;
            else 
                return true;
        }
        return false;        
    }    
};