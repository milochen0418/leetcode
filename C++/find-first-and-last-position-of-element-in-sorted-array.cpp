class Solution {
    //https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
    //article https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/discuss/2110058/C%2B%2B-or-simple-binary-search-solution-or-explanation-easy
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5381846665171114
public:
    vector<int> searchRange(vector<int>& a, int t) {
        vector<int> ans = vector<int>(2,-1);
        int L,R;
        L=0;
        R=a.size()-1;
        while(L<=R) {
            int M = L+(R-L)/2;
            if(a[M]==t && (M-1<0 || a[M-1]<t) ) {
                ans[0]=M;
                break;
            }
            if(t<=a[M])
                R=M-1;
            else
                L=M+1;
        }
        if(ans[0]==-1) return ans;
        L = ans[0];
        R = a.size()-1;
        while(L<=R) {
            int M = L+(R-L)/2;
            if(a[M]==t && (M+1>=a.size() || a[M+1]>t)) {
                ans[1] = M;
                return ans;
            }
            if(a[M]<=t)
                L=M+1;
            else 
                R=M-1;
        }
        return ans;
    }

    vector<int> searchRangeOptimizedFromAbove(vector<int>& a, int t) {
        vector<int> ans = vector<int>(2,-1);
        int L=0,R=a.size()-1,M;
        while(L<=R) {
            M = L+(R-L)/2;
            if(a[M]==t && (M-1<0 || a[M-1]<t) ) {
                ans[0] = M;
                R = a.size()-1;
                while(L<=R) {
                    M = L+(R-L)/2;
                    if(a[M]==t && (M+1>=a.size() || a[M+1]>t)) {
                        ans[1] = M;
                        return ans;
                    }
                    if(a[M]<=t) L=M+1; else R=M-1;
                }
            }
            if(t<=a[M]) R=M-1; else L=M+1;
        }
        return ans;
    }
    vector<int> searchRangeOld(vector<int>& a, int t) {
        //[    5,  7,  7,   8,   8,  10]
        //   0   1   2    3    4   5
        vector<int> ans = vector<int>(2,0);
        ans[0] = searchRangeStart(a,t);
        ans[1] = searchRangeEnd(a,t);
        return ans;
    }
    
    int searchRangeStart(vector<int>& a, int t) {
        //[    5,  7,  7,   8,   8,  10]
        //   0   1   2    3    4   5
        int n = a.size(),L = 0, H = n-1; //element is [i]&i+1
        while(L<=H) { 
            int M = L + (H-L) / 2;
            //cout<<"M = "<<M<<"\n";
            //printf("(H,L)->M is (%d,%d)->%d\n", L, H, M);
            if(a[M] == t && (M==0 || a[M-1]<t) )   {
                return M;
            }
            else if(t>a[M]) {
                L=M+1;
            } else { //equal to if( t < a[M] || (a[M] == t && a[M-1] ==t) ) 
                H=M-1;
            }
        }
        return -1;
    }
    
    int searchRangeEnd(vector<int>& a, int t) {
        //[    5,  7,  7,   8,   8,  10]
        //   0   1   2    3    4   5
        int n = a.size(),L = 0, H = n-1; //element is [i]&i+1
        while(L<=H) { 
            int M = L + (H-L) / 2;
            //cout<<"M = "<<M<<"\n";
            //printf("(H,L)->M is (%d,%d)->%d\n", L, H, M);
            if(a[M] == t && (M+1==n || a[M+1]>t) )   {
                return M;
            } else if( t<a[M]) { 
                H=M-1;
            } else {
                L=M+1;
            }
        }
        return -1;        
    }
};