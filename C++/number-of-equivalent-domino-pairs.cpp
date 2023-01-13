class Solution {
    //https://leetcode.com/problems/number-of-equivalent-domino-pairs/
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        //NlogN solution by sorting
        dominoes.push_back({10,11});
        int n = dominoes.size();
        for(auto &v:dominoes) if(v[0]>v[1]) swap(v[0],v[1]);
        
        sort(dominoes.begin(), dominoes.end(), [](auto &lhs, auto &rhs) {
            int l = lhs[0]*10+lhs[1];
            int r = rhs[0]*10+rhs[1];
            return l<r;
        });
        
        int cnt=1, ans=0;
        for(int i = 1;i<n;i++) {
            if(dominoes[i]==dominoes[i-1]) {
                cnt++;
            } else {
                if(cnt>=2) {
                    ans+=(cnt*(cnt-1))/2;
                    cnt=1;
                }
            }
        }
        return ans;
    }
};