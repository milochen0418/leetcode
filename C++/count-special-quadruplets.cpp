class Solution {
    //https://leetcode.com/problems/count-special-quadruplets
public:
    int countQuadruplets(vector<int>& nums) {
        int n=nums.size();
        vector<int>& A=nums;
        int ans = 0;
        for(int i = 0; i<n;i++) {
            for(int j =i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    for(int l=k+1;l<n;l++) {
                        if(A[i]+A[j]+A[k] == A[l]) ans++;    
                    }
                }
            }
        }
        return ans;
    }
};