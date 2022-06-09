class Solution {
    //https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x
public:
    int specialArray(vector<int>& a) {
        int n = a.size();
        for(int x = 0; x<=n;x++) {
            int cnt = 0;
            for(int i = 0; i<n;i++) {
                if(a[i]>=x) cnt++;
            }
            if(cnt==x) return x;
        }
        return -1;
    }
};