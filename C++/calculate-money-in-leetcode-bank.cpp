class Solution {
    //https://leetcode.com/problems/calculate-money-in-leetcode-bank
public:
    int totalMoney(int n) {
        const vector<int> prefix_v = {1,3,6,10,15,21,28};
        n-=1;
        int ans = 0, i = 0;
        int q = n/7;//q weeks
        int r = n%7;//remain day
        for(i = 0; i<q;i++) ans += prefix_v[6] + 7*i;
        ans += (r+1)*(q) + prefix_v[r];
        return ans;        
    }
    int totalMoney_v01(int n) {
        n-=1;
        vector<int> v = vector<int>(7,0); //0:Mon, 1:Tue...5:Sat. 6:Sun
        vector<int> prefix_v = vector<int>(7,0);
        for(int i = 0;i<7;i++) {
            v[i]=i+1;
            prefix_v[i] = v[i];
            prefix_v[i] = (i-1<0?0:prefix_v[i-1]) + prefix_v[i];
        }
        //for(auto &i:prefix_v)printf("%d,",i);
        //printf("\n");
        int ans = 0, i = 0;
        int q = n/7;//q weeks
        int r = n%7;//remain day
        
        for(i = 0; i<q;i++) {
            ans += prefix_v[6] + 7*i;
            //printf("ans=%d\n", ans);
        }
        ans += (r+1)*(q) + prefix_v[r];
        return ans;        
    }
};