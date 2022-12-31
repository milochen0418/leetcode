/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int m = binaryMatrix.dimensions()[0];
        int n = binaryMatrix.dimensions()[1];
        int ans = INT_MAX;
        for(int i =0;i<m;i++) {
            int first_one = INT_MAX; 
            int L=0,R=n-1;
            while(L<=R) {
                int M = L + (R-L)/2;
                int AM = binaryMatrix.get(i, M);
                if(AM==0) {
                    L=M+1;
                } else {
                    int AM_1 = M-1>=0?binaryMatrix.get(i, M-1):0;    
                    if(AM_1==1) {
                        R=M-1;
                        continue;
                    }
                    first_one=M;
                    break;
                }
            }
            ans = min(ans, first_one);
        }
        return ans==INT_MAX?-1:ans;
    }

    int leftMostColumnWithOne_v02(BinaryMatrix &binaryMatrix) {
        //You made too many calls to BinartMatrix.get().
        int m = binaryMatrix.dimensions()[0];
        int n = binaryMatrix.dimensions()[1];
        int ans = INT_MAX;
        for(int i =0;i<m;i++) {
            int first_one = INT_MAX; 
            int L=0,R=n-1;
            while(L<=R) {
                int M = L + (R-L)/2;
                int AM = binaryMatrix.get(i, M);
                int AM_1 = M-1>=0?binaryMatrix.get(i, M-1):0;
                if(AM_1==0 && AM==1) {
                    first_one = M;
                    break;
                }
                if(AM==0) 
                    L=M+1;
                else
                    R=M-1;
            }
            ans = min(ans, first_one);
        }
        return ans==INT_MAX?-1:ans;

    }

    int leftMostColumnWithOne_v01(BinaryMatrix &binaryMatrix) {
        //It's O(N^2) alogirthm to many call
        int m = binaryMatrix.dimensions()[0];
        int n = binaryMatrix.dimensions()[1];
        int ans = INT_MAX;
        for(int i =0;i<m;i++) {
            int first_one = INT_MAX; 
            for(int j=0;j<n;j++) {
                if(binaryMatrix.get(i,j)==1) {
                    first_one = j;
                    break;
                }
            }
            ans = min(ans, first_one);
        }
        return ans==INT_MAX?-1:ans;
    }
};