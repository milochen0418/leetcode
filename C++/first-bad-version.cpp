// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
    //https://leetcode.com/problems/first-bad-version
    //https://leetcode.com/problems/first-bad-version/discuss/2109813/C%2B%2B-or-simple-binary-search-solution-or-explanation
public:
    int firstBadVersion(int n) {
        int L=1,R=n;
        while(L<=R) {
            int M = L+(R-L)/2;
            if(isBadVersion(M)  && (M-1<1 || !isBadVersion(M-1)) ) {
                return M;
            }
            if(isBadVersion(M)) 
                R=M-1;
            else 
                L=M+1;
        }
        return -1; //The code will not be wrong becuase so there's no such case happened
    }

    int firstBadVersionOld(int n) {
        /*
        if(isBadVersion(1))return 1;
        for(int i = 1; i<=n-1;i++ ) {
            if(isBadVersion(i) == false && isBadVersion(i+1) == true ) { 
                return i+1;
            }
        }*/
        
        
        int L = 1;
        int H = n ; 
        int m = L + (H-L)/2; //(5+1)/2 = 3    [1,2,_3,4,5]
        
        
        while(L<=H) {
            int m = L+(H-L)/2;
            //(5+1)/2 = 3    [1,2,_3,4,5]
            //(3+5)/2 = 4 [3,_4,5]
            
            if(isBadVersion(m))  { // case m is bad
                if(m==1 || isBadVersion(m-1)==false) return m;
                H = m;
            } else { //case m is not bad
                if(m+1 <= n && isBadVersion(m+1)==true) return m+1;
                L = m; //(L,H)=(3,5)
            }
        }
        
        return 0;
    }
};


/* tescase
5
4
1
1
2126753390
1702766719
*/