class Solution {
    //https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/
    //article https://leetcode.com/problems/maximum-odd-binary-number/discuss/4103079/C%2B%2B-2-pass-and-1-pass-O(n)-solution-with-O(1)-space
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