class Solution {
    //https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        //total >= cost1*x + cost2*y 
        //total - cost1*x - cost2*y >= 0
        typedef long long ll;
        ll ans = 0;
        int n = total / cost1;
        for(int x = 0; x<=n; x++) {
            int pre = total - cost1*x;
            /*
            while(pre>=0) {
                ans++;
                pre -= cost2;
            }*/ 
            if(pre>=0) ans+=(1+ (pre/cost2));
        }
        return ans;
        
    }
};