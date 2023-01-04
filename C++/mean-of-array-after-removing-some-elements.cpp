class Solution {
    //https://leetcode.com/problems/mean-of-array-after-removing-some-elements
    //article https://leetcode.com/problems/mean-of-array-after-removing-some-elements/discuss/2995045/C%2B%2B-simple-4-lines-by-sort
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size(), m = n/20, sum = 0;
        sort(arr.begin(), arr.end());
        for(int i = m;i<n-m;i++) sum+=arr[i];
        return ((double)sum)/(n-2*m);        
    }
};