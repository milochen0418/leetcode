class Solution {
    //https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        vector<vector<int>> v = vector<vector<int>>(n, vector<int>(2,0));
        for(int i = 0; i<n;i++) {
            v[i][0] = nums[i];
            v[i][1] = i;
        }
        sort(v.begin(), v.end(), [](auto&lhs, auto&rhs) {
            if(lhs[0]==rhs[0])
                return lhs[1]<rhs[1];
            else 
                return lhs[0]>rhs[0];
        });
        
        vector<vector<int>> w;
        for(int i =0;i<k;i++) w.push_back(v[i]);
        
        sort(w.begin(), w.end(), [](auto&lhs, auto&rhs){
            return lhs[1]<rhs[1];
        });
        for(auto &p:w) ans.push_back(p[0]);
        return ans;
    }
};