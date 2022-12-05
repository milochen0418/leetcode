class Solution {
    //https://leetcode.com/problems/find-the-k-beauty-of-a-number
public:
    int divisorSubstrings(int num, int k) {
        string A = to_string(num);
        int cur=0,n =A.size(), ans = 0;
        for(int i =0;i<k;i++) cur= cur*10+(A[i]-'0');
        ans+=(num%cur==0);
        for(int i=k;i<n;i++) {
            int L=i-k, R=i;
            cur=cur*10;
            cur=cur-(pow(10,k)*(A[L]-'0'));
            cur=cur+(A[R]-'0');
            if(cur>0)ans+=(num%cur==0);
        }
        return ans;
    }
};