class Solution {
    //https://leetcode.com/problems/add-to-array-form-of-integer
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>& A = num;
        if(k==0) return A;
        reverse(A.begin(), A.end());
        vector<int> B;
        while(k>0) {
            B.push_back(k%10);
            k/=10;
        }
        int n = max(A.size(),B.size());
        vector<int> ans=vector<int>(n, 0);
        int carry = 0;
        for(int i = 0;i<n;i++) {
            int A_i = i<A.size()?A[i]:0;
            int B_i = i<B.size()?B[i]:0;
            int sum = A_i + B_i + carry;
            ans[i] = sum%10;
            carry = sum/10;    
        }
        if(carry>0)ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};