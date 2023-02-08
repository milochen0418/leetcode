class Solution {
    //https://leetcode.com/problems/most-common-word
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        unordered_set<string> bset;
        for(auto &s:banned) {
            for(auto &c: s) 
                if('A'<=c && c<='Z') 
                    c = c-'A'+'a';
            bset.insert(s);
        }
        
        unordered_map<string,int> mp;
        string &p= paragraph;
        p.push_back(' ');
        string w,ans;
        int maxv = 0;
        for(auto &c:p) {
            if('A'<=c && c<='Z') 
                c = c-'A'+'a';
            if('a'<=c && c<='z') {
                w.push_back(c);
            } else {
                if(w.length()==0) continue;
                if(bset.find(w) == bset.end()) {
                    if(++mp[w]>maxv) {
                        ans=w;
                        maxv=mp[w];
                    }
                }
                w="";
            }
        }
        return ans;
    }
};