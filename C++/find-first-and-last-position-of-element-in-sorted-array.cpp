class Solution {
public:
    vector<int> searchRange(vector<int>& a, int t) {
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