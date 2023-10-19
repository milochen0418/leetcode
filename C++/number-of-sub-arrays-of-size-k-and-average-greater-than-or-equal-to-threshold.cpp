class Solution {
    //https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0, chkv = threshold * k, sum = 0, n = arr.size();
        for(int i = 0; i<k; i++) sum+=arr[i];
        ans = (sum >= chkv);
        for(int i = k; i<n; i++) {
            sum = sum - arr[i-k] + arr[i];
            ans += (sum >= chkv);
        }
        return ans;
    }
};