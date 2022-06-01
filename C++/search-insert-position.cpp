class Solution {
    //https://leetcode.com/problems/search-insert-position/
public:
    int searchInsert(vector<int>& a, int target) {
        int L=0, R=a.size()-1;
        while(L<=R) {
            int M = L+(R-L)/2;
            if(target > a[M]) {
                L=M+1;
            } else if(target < a[M]) {
                R=M-1;
            } else { //a[M]==target
                return M;
            }
        }
        return L;
    }
    int searchInsertAnswer2(vector<int>& a, int target) {    
        //   [1,3,5,6]
        //   0 1 2 3 4  <- there are five insertion position
        int L = 0, R=a.size()-1;
        while(L<=R) {
            int M = L+(R-L)/2;
            printf("a[M=%d]=%d\n",M, a[M]);
            if( (M==0 || a[M-1]<t) && t<=a[M]) {
                printf("hit M=%d\n",M);
                return M;                
            } else if(M>=a.size() || a[M]<t) {
                printf("(L=%d -> L=%d, R=%d)\n",L, M+1,R);
                L = M+1;
            } else if( M==0 || t<=a[M-1]) {
                printf("(L=%d,R=%d -> R=%d)\n",L, R, M-1);
                R = M-1;
            }
        }
        return L;
    }
    int searchInsertAnswer3(vector<int>& a, int target) {    
        int L=0, R=a.size()-1;
        while(L<=R) {
            int M = L+(R-L)/2;
            if( (M-1<0 || a[M-1]<t) && t<=a[M]) return M; // case match
            if(a[M]<t) { // case larger
                L= M+1;
                if(L>=a.size())return a.size();
            } else { // case small
                R = M-1;
                if(R<=0) return 0;//this case is included in the match case
            }
        }
        return -1;
    }

    int searchInsertAnswer4ByDummy(vector<int>& a, int t) {
        a.push_back(INT_MAX);
        int L=0, R=a.size()-1;
        while(L<=R) {
            int M = L+(R-L)/2;
            int aM_1 = M-1>=0?a[M-1]:INT_MIN;
            if(aM_1<t && t<=a[M]) return M;
            if(a[M]<t) {
                L= M+1;
            } else {
                R = M-1;
            }
        }
        return -1;
    }


};