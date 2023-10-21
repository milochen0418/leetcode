class Solution {
    //https://leetcode.com/problems/the-k-strongest-values-in-an-array
    //article https://leetcode.com/problems/the-k-strongest-values-in-an-array/discuss/4192637/C%2B%2B-simple-13-lines-using-sort
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<vector<int>> v;
        int n = arr.size();
        for(int i = 0; i<n; i++) 
            v.push_back({arr[i], i});
        sort(arr.begin(), arr.end());
        int m = arr[(n-1)/2];        
        sort(v.begin(), v.end(), [&](auto &lhs, auto &rhs) {
            int L=abs(lhs[0]-m), R=abs(rhs[0]-m);
            return (L==R)?(lhs[0]>rhs[0]):(L>R);
        });
        vector<int> ans;
        for(int i = 0; i<k; i++) ans.push_back(v[i][0]);
        return ans;
    }
};