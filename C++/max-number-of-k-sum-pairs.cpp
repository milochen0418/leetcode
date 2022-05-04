class Solution {
    //https://leetcode.com/problems/max-number-of-k-sum-pairs
    //Article https://leetcode.com/problems/max-number-of-k-sum-pairs/discuss/2006689/C%2B%2B-or-binary-search-approach-or-O(N*log-N-)
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5288808587808256/
public:
    int maxOperationsByHashMap(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> mp;
        for(auto &i: nums) mp[i]+=1;
        for(auto &[key,val]:mp) {
            int t = k-key;
            if(t==key) {
                ans += val/2;
            } else if(mp.find(t) != mp.end()) {
                int cnt = min(val, mp[t]);
                ans += cnt;
                mp[key] -= cnt;
                mp[t]-=cnt;   
            }
        } 
        return ans;  
    }

    int maxOperationsImproveSearchByHashMap(vector<int>& nums, int k) {
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
            //Change to use hash map
            if(mp.find(t) != mp.end()) {
                int cnt = min(mp[a[i].first], mp[t]);
                ans+=cnt;
                mp[a[i].first]-=cnt;
                mp[t]-=cnt;
            }
            
        }
        return ans;  
    }

    int maxOperationsBinarySearch(vector<int>& nums, int k) {
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