class Solution {
    //https://leetcode.com/problems/find-all-anagrams-in-a-string/
    //https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/1739954/C%2B%2B-or-O(N)-or-step-by-step-or-slide-window
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v, sv(26), pv(26);
        int p_len = p.length();
        int s_len = s.length();
        if(p_len>s_len) return v;
        
        for(int i=0; i<p.length(); i++) {
            pv[p[i]-'a'] +=1;
            sv[s[i]-'a'] +=1;
        }
        if(pv==sv) v.push_back(0);
        for(int i=1; i<s_len-p_len+1;i++) {
            sv[s[i-1]-'a']-=1;
            sv[s[i+p_len-1]-'a']+=1;
            if(pv==sv) v.push_back(i);            
        }
        return v;
    }
};