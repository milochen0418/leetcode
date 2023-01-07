class Solution {
    //https://leetcode.com/problems/maximum-ice-cream-bars
    //Study Counting Sort https://leetcode.com/explore/learn/card/sorting/695/non-comparison-based-sorts/4437/
    //article https://leetcode.com/problems/maximum-ice-cream-bars/discuss/3011618/C%2B%2B-or-3-approach-(sort-priority-queue-counting)
public:
    typedef long long ll;
    int maxIceCream(vector<int>& costs, int coins) {
        int maxv = INT_MIN;
        for(auto &i:costs) maxv = max(maxv, i);
        vector<int> mp=vector<int>(maxv+1,0);
        for(auto &i: costs) mp[i]++;
        int ans = 0;
        for(int i = 0;i<mp.size() && coins>0;i++) {
            ll product = (ll)i*(ll)mp[i];
            //printf("i=%d, mp[i]=%d\n", i,mp[i]);
            if((ll)coins >= product) {
                coins -= i * mp[i];
                ans = ans + mp[i];
            } else {
                ans = ans + coins/i;
                coins = 0;
            }
        }
        return ans;
    }

    int maxIceCream_v02(vector<int>& costs, int coins) {
        //sorting
        int ans = 0;
        sort(costs.begin(),costs.end());
        for(auto &i: costs) {
            coins -= i;
            if(coins>=0) 
                ans++;
            else
                break;
        }
        return ans;
    }

    int maxIceCream_v01(vector<int>& costs, int coins) {
        //priority_queue
        int ans=0;
        priority_queue<int, vector<int>, greater<int>> minQ;
        for(auto &i:costs) minQ.push(i); 
        while(!minQ.empty()) {
            coins -= minQ.top();
            minQ.pop();
            if(coins >=0) 
                ans++;
            else 
                break;
        }
        return ans;
    }
};