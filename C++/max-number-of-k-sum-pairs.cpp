class Solution {
    //https://leetcode.com/problems/max-number-of-k-sum-pairs
    //Article https://leetcode.com/problems/max-number-of-k-sum-pairs/discuss/2006689/C%2B%2B-or-binary-search-approach-or-O(N*log-N-)
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> mp;
        for(auto &i: nums) mp[i]+=1;
        vector<pair<int,int>> a;
        for(auto &[key,val]:mp) a.push_back({key,val});
        sort(a.begin(), a.end(), [](auto& lhs, auto& rhs) {
            return lhs.first< rhs.first;
        });
        
        int n = a.size();
        for(int i = 0;i<n;i++) {
            int t = k-a[i].first;
            if(t==a[i].first) {
                ans += a[i].second/2;
                continue;
            }
            
            int L=i+1,R=n-1;
            while(L<=R) {
                int M = L+(R-L)/2;
                if(a[M].first == t) {
                    int cnt = min(a[M].second, a[i].second);
                    ans += cnt;
                    break;
                } else if(t<a[M].first) {
                    R = M-1;
                } else {
                    L = M+1;
                }
            }                
            
        }
        return ans;
    }
};