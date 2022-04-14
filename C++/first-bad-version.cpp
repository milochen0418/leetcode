// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
    //https://leetcode.com/problems/first-bad-version
public:
    int firstBadVersion(int n) {
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