class Solution {
    //https://leetcode.com/problems/k-items-with-the-maximum-sum/
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int posone = numOnes;
        int zero = numZeros;
        int negone = numNegOnes;
        if(posone >= k) return k;
        int ans = posone;
        k-=posone;
        k-=zero;
        if(k>=0) {
        	ans-=k;
        }            
        return ans;
    }
};