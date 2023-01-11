class Solution {
    //https://leetcode.com/problems/missing-number-in-arithmetic-progression
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int mind = INT_MAX;
        int maxd = INT_MIN;
        for(int i = 1;i<n;i++) {
            int d = arr[i]-arr[i-1];
            mind = min(mind, d);
            maxd = max(maxd, d);
            if(maxd!=mind) break;
        }
        if(mind<0)swap(mind,maxd);
        
        for(int i = 1;i<n;i++) {
            int d = arr[i]-arr[i-1];
            if(d!=mind) return arr[i-1]+mind;
        }
        return arr[0];//for some case like [1,1,1]
    }
};