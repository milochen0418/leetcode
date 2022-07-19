class Solution {
    //https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0, n = arr.size();
        vector<int> a = vector<int>(n,arr[0]);//Let a be the prefix sum of arr
        for(int i = 1;i<n;i++) a[i] = arr[i] + a[i-1];
        for(int m = 0;m<n;m+=2) 
            for(int i=n-1;i-m-1>=-1 ;i--) 
                ans+=a[i]-((i-m-1)<0?0:a[i-m-1]);
        return ans;
    }
};