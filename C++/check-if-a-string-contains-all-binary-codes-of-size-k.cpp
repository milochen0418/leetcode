class Solution {
    //https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k
public:
    bool hasAllCodes(string s, int k) {
        using ll = long long;
        int n = s.length();
        if(n<k) return false;
        unordered_map<ll,int> mp;
        ll val = 0;
        for(int i = 0; i<k;i++) val = (val<<1) + (s[i]-'0');
        mp[val]++;
        
        for(int i = k; i<n; i++) {
            val = (val<<1) + (s[i]-'0');    
            if( (val&(1<<k)) > 0) val-=1<<k;
            mp[val]++;
        }
        for(int i = 0; i< 1<<k; i++) if(mp[i] == 0) return false;
        
        return true;
    }
};