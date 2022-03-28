class Solution {
    //https://leetcode.com/problems/search-in-rotated-sorted-array
public:
    int search(vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1; 
        int t = target; 
        return rotSearch(L, R, t, nums);
    }
        
    int binSearch(int L, int R, int t, vector<int>& a) {
        while(L<=R) {
            int M = L + (R-L); // (L+H)/2;
            if(t<a[M]) {
                R = M-1;
            } else if(t>a[M]) {
                L = M+1;
            } else {
                return M;
            }
        }
        return -1;        
    }
    
    
    int rotSearch(int L, int R, int t, vector<int>& a) {
        if (L > R) return -1;
        int M = L + (R-L)/2; //(L + R) / 2;
        if (a[M] == t) return M;
        
        //case 1
        if (a[L] <= a[M] && a[M] <= a[R]) {
            return binSearch(L, R, t,a);
        } else {            
            //case 2   
            if (a[L] <= a[M] && a[R] <= a[L]) {
                if (a[L] <= t && t <= a[M]) {
                    //return rotSearch(L, M - 1, t,a );
                    return binSearch(L, M - 1, t,a);
                } else {
                    return rotSearch(M + 1, R, t,a);  
                }
            }    
            //case 3
            if (a[M] <= a[R] && a[L] >= a[R]) {
                if (a[M] <= t && t <= a[R]) {
                    //return rotSearch(M + 1, R, t,a );
                    return binSearch(M + 1, R, t,a);
                } else {
                    return rotSearch(L, M - 1, t,a);
                }
            }  
            //case otherwise      
            return -2; //Un-expected Error. 
        }    
    }    
};