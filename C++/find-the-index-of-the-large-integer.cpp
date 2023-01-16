/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
    //https://leetcode.com/problems/find-the-index-of-the-large-integer
    //article https://leetcode.com/problems/find-the-index-of-the-large-integer/discuss/3057233/C%2B%2B-Binary-Search-O(logN)
public:
    int getIndex(ArrayReader &reader) {
        int n = reader.length();
        int L = 0, R=n-1;
        while(L<=R) {
            n=R-L+1;
            if(L==R) return L;            
            int M = L+(R-L)/2;
            int ret = reader.compareSub(L,M-n%2,M+1,R);
            if(ret == 0) return M;
            if(ret>0)
                R=M-n%2;
            else 
                L=M+1;
        }
        return -1;            
    }

    int getIndex_v01(ArrayReader &reader) {
        int n = reader.length();
        int L = 0, R=n-1;
        while(L<=R) {
            n=R-L+1;
            if(L==R) return L;
            if(n%2==1) {
                int M = L+(R-L)/2;
                //printf("n%2==1, L,M,R=%d,%d,%d compare[%d..%d][%d..%d]\n",L,M,R, L,M-1,M+1,R);
                int ret = reader.compareSub(L,M-1,M+1,R);
                if(ret == 0) return M;
                if(ret>0)
                    R=M-1;
                else 
                    L=M+1;
            } else { //case n%2==0
                int M = L+(R-L)/2;//L=0,R=3->M=1
                //printf("n%2==0, L,M,R=%d,%d,%d compare[%d..%d][%d..%d]\n",L,M,R, L,M,M+1,R);
                int ret = reader.compareSub(L,M,M+1,R);
                if(ret>0) 
                    R=M;
                else 
                    L=M+1;
            }
        }
        return -1;
            
    }
};