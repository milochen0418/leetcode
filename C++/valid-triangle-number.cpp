class Solution {
    //https://leetcode.com/problems/valid-triangle-number
    //article https://leetcode.com/problems/valid-triangle-number/discuss/2188063/C%2B%2B-or-binary-search-approach
public:
    int triangleNumber(vector<int>& nums) {
        //When a <= b <= c
        //if a+b > c, then
        //a+c > b
        //b+c > a
        //so, we just need to find a<=b, and search maximum c s.t. a+b>c
        vector<int> &a = nums;
        int n = a.size();
        sort(a.begin(), a.end());
        int ans = 0;
        //[2,2,3,4]
        for(int i =0;i<n;i++) {
            for(int j = i+1;j<n;j++) {
                //printf("(i,j)=(%d,%d)\n",i,j);
                int t = a[i]+a[j];//t = a+b
                //int L = j+1, R = n-1;
                int L = j, R = n-1;
                //find maximum c s.t. t>c, a[M] < t <=a [M+1]
                while(L<=R) { 
                    int M = L+(R-L)/2;
                    //printf("i=%d,j=%d, M=%d\n",i,j,M);
                    if( (M==j||t>a[M]) &&  (M+1>=n||t<=a[M+1])) {
                        //printf("ans+= M-j = %d-%d = %d\n",M,j,M-j);
                        ans+=M-j;
                        break;
                    }  else {
                        //printf("Not matched\n",M,j,M-j);
                    }
                    if( (M==j||t>a[M]) ) L=M+1; else R=M-1;
                }
            }
        }
        return ans;
    }
};