class Solution {
    //https://leetcode.com/problems/kth-missing-positive-number/
public:
    int findKthPositive(vector<int>& arr, int k) {
        //Observation of A[i] - i -1
        //e.g. A = [3, 6, 9, 14]
        //A[0] - 0 - 1 = 2  -> 1,2
        //A[1] - 1 - 1 = 4  -> 1,2,4,5
        //A[2] - 2 - 1 = 6  -> 1,2,4,5,7,8
        //A[3] - 3 - 1 = 10 -> 1,2,4,5,7,8,10,11,12,13
        int R = arr.size() + k; 
    }
};