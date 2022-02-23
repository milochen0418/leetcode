class Solution {
    //https://leetcode.com/problems/fixed-point
    //article https://leetcode.com/problems/fixed-point/discuss/1794210/C%2B%2B-or-3-lines-O(n)-or-binary-search-O(logN)
public:
    int fixedPoint(vector<int>& arr) {
        int n = arr.size(), ans=-1;
        int m, L = 0, H=n-1;
        while(L<=H) {
            m = (L+H)/2;
            if(arr[m] == m) ans = m;
            if(arr[m] >= m) H = m-1;
            if(arr[m] < m) L = m+1;
        }
        return ans;
    }
    
    int ans2(vector<int>& arr) {
        int i = 0, n = arr.size();
        while(i<n && arr[i]!=i)i++;
        return i==n ? -1 : i;
    }
    
};