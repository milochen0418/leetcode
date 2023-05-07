class Solution {
    //https://leetcode.com/problems/find-the-distinct-difference-array/
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int>& A = nums;
        int n = A.size();
        vector<int> ans = vector<int>(n,0);
        for(int i = 0; i<n;i++) {
            unordered_set<int> pre;
            unordered_set<int> suf;
            for(int k=0;k<=i;k++) {
                pre.insert(A[k]);
            }
            for(int k=i+1;k<n;k++){
                suf.insert(A[k]);
            }
            
            ans[i] = pre.size() - suf.size();
            //printf("%d - %d -> ans[%d] = %d\n", pre.size(),suf.size(),i,ans[i]);
        }
        return ans;
    }
};