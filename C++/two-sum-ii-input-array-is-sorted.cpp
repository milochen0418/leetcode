class Solution {
    //https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans = vector<int>(2,-1);
        int n = a.size();
        for(int i = 0; i<n;i++) {
            int t = target - a[i];
            int L = i+1, R=n-1;
            while(L<=R) { 
                int M = L + (R-L)/2;
                if(a[M] == t) {
                    ans[0]=i+1;
                    ans[1]=M+1;
                    return ans;
                }
                if(t>a[M]) L=M+1; else R=M-1;
            }
            
        }
        return ans;      
    }
};