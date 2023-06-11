class Solution {
    //https://leetcode.com/problems/collecting-chocolates/
public:
    typedef long long ll;
    long long minCost(vector<int>& nums, int x) {
        ll ans=0;
        int n = nums.size();
        vector<ll> mincosts = vector<ll>(n,0);//current mincosts array for each iteration
        ll base = 0;
        for(int i = 0;i<n;i++) {
            mincosts[i] = (ll)nums[i];
            ans+=mincosts[i];
        }
        //For now, ans is the minimum cost for no turning  
        
        for(int i = 1;i<n;i++) { //iterations for turning 
            ll potans = 0;
            for(int j = 0;j<n;j++) {
                mincosts[j] = min(mincosts[j], (ll)nums[(j+i)%n]);
                potans+=mincosts[j];
            }
            
            base = base + (ll)x;
            potans = potans + base;
            ans = min(ans,potans);
        }
        
        return ans;
    }
};