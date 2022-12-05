class Solution {
    //https://leetcode.com/problems/remove-letter-to-equalize-frequency
public:
    bool equalFrequency(string word) {
        /*
        a.cnt = 5
        b.cnt = 5
        c.cnt = 5
        d.cnt = 6 
        
        mp[a]=5
        mp[b]=5
        mp[c]=5
        mp[d]=6
        
        mmp[5]=3
        mmp[5+1]=1
        
        Some case like
        "bac" will be true, what does it look like?
        mmp[1]=3
        
        Some case like
        "abbcc" will be true, what does it look like?
        mp[a]=1
        mp[b]=2
        mp[c]=2
        
        mmp[2]=2
        mmp[1]=1
        
        
        
        */
        
        
        unordered_map<char,int> mp;
        unordered_map<int,int> mmp;
        vector<int> v;
        for(auto&c:word) mp[c]++;
        for(auto&[c,i]:mp) mmp[i]++;
        for(auto&[i,j]:mmp) v.push_back(i);
        if(mp.size()==1) return true;//for edge case  "zz"
        if(v.size()==1 && mmp.find(1)!=mmp.end()) return true; //for edge case "bac"
        if(v.size()!=2) return false;
        if(v[0]>v[1])swap(v[0],v[1]);
        if(v[0]==1 && mmp[v[0]]==1) return true; //for edge case like "abbcc"
        if(v[0]+1 != v[1]) return false;
        if(mmp[v[1]]!=1) return false;
        return true;
        
    }
};