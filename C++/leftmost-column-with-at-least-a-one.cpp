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