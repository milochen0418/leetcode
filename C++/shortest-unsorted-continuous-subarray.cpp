class Solution {
    //https://leetcode.com/problems/shortest-unsorted-continuous-subarray
public:
    int findUnsortedSubarray(vector<int>& a) {
        vector<int> b = a;
        int n = a.size();
        sort(b.begin(), b.end());
        int min_idx = -1;
        int max_idx = -1;
        for(int i = 0; i < n;i++) {
            if(a[i]!=b[i]){
                min_idx = i;
                break;
            }
        }
        
        for(int i = n-1; i >= 0;i--) {
            if(a[i]!=b[i]){
                max_idx = i;
                break;
            }
        }
        
        if(min_idx == -1 && max_idx == -1) return 0;
        return max_idx - min_idx + 1;
    }
};