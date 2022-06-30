class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        vector<int> a;
        for(auto &i:nums) a.push_back(i);
        for(auto &i:nums) a.push_back(i);
        int n = a.size();
        int w = a.size()/2;
        int L,R,acc;
        int ans = INT_MIN;
        L=0;R=0;acc =0;
        while(L<n && R<n ) {
            acc = acc + a[R];
            ans = max(ans, acc);
            if(acc<0) {
                L=R+1;
                R=R+1;
                acc = 0;
            } else {
                R=R+1;
            }
            
            if(R-L+1>w) {
                /*
                acc = acc - a[L];
                L=L+1;
                */
                R=L+1;
                L=L+1;
                acc = 0;
            }
        }
        return ans;
    }
};