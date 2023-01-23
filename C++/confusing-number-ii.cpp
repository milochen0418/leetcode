class Solution {
    //https://leetcode.com/problems/confusing-number-ii
public:
    int confusingNumberII(int n) {
        int ans=0;
        for(int i = 1;i<=n;i++) ans+=is_confusing_number(i);
        return ans;
    }
    const vector<int> mp={0, 1,-1,-1,-1,-1, 9,-1, 8, 6};
    int is_confusing_number(int n) {
        int v=n,m=0;
        while(v>0) {
            if(mp[v%10]==-1) return 0;
            m = m*10 + mp[v%10];
            v/=10;
        }
        return n!=m;
    }  
};