class Solution {
    //https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/
public:
    int maximizeSum(vector<int>& nums, int k) {
        int n = s.length(), L = 0, R=n-1, i = 0;
        while(L<R) 
            if(s[L]=='1')i=L++;
            else if(s[R] == '0') R--;
            else swap(s[i=L], s[R]);
        swap(s[i],s[n-1]);
        return s;
    }
};