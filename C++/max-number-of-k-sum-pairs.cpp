class Solution {
    //https://leetcode.com/problems/max-number-of-k-sum-pairs
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
        
        //make sorted array. a[i].first is number. a[i].second is how many repeaed number for a[i].first
        int n = a.size();
        for(int i = 0;i<n;i++) {
            if(a[i].second==0) continue;
            int t = k-a[i].first;
            //printf("a[%d]=%d, k=%d, t=%d", i,a[i],k, t);
            //cout<<"\n";
            int L=i,R=n-1;
            while(L<=R) {
                int M = L+(R-L)/2;
                if(a[M].first == t) {
                    
                    if(M==i) {
                        int cnt = a[M].second/2;
                        ans+=cnt;
                        a[M].second -= cnt;
                        //cout<<"match same\n";
                        break;
                        
                    } else {
                        int cnt = min(a[M].second, a[i].second);
                        ans += cnt;
                        a[M].second -= cnt;
                        a[i].second -= cnt;
                        //cout<<"match\n";
                        break;                        
                    }
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