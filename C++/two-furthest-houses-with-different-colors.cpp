class Solution {
    //https://leetcode.com/problems/two-furthest-houses-with-different-colors/
public:
    int maxDistance(vector<int>& colors) {
        //Greedy Algorithm with Time complexity : O(N)
        int n = colors.size();
        int L = 0, R=n-1;
        if(colors[L]!=colors[R]) return R-L;
        while(L<n && colors[0]==colors[L])L++;
        while(R>=0 && colors[n-1]==colors[R])R--;
        return max(max(L-0, n-1-L), max(R-0, n-1-R));
    }
    
};