class Solution {
    //https://leetcode.com/problems/find-original-array-from-doubled-array
public:
    vector<int> findOriginalArray(vector<int>& changed) { 
        vector<int> ans = vector<int>();
        unordered_map<int,int> mp; 
        for(auto &i: changed) mp[i]++; 
        vector<int> v = vector<int>();
        for(auto &[k,val]:mp) v.push_back(k);
        sort(v.begin(), v.end());
        
        if(mp[0]%2!=0) return vector<int>();//edge case for zero
        
        for(auto &i: v) {
            if(i!=0) {
                if(mp[i]>mp[i*2]) return vector<int>();
                for(int j=0;j<mp[i];j++) ans.push_back(i);
                mp[i*2] -= mp[i];
                mp[i] = 0;
            } else {
                //edge case for zero
                for(int j =0;j<mp[i]/2;j++) ans.push_back(i);
            }
        } 
        return ans;
    }
};