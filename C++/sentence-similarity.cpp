class Solution {
    //https://leetcode.com/problems/sentence-similarity
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int n = sentence1.size();
        if(n!=sentence2.size()) 
            return false;
        
        unordered_map<string,unordered_set<string>> mp;
        for(auto &pair:similarPairs) {
            mp[pair[0]].insert(pair[1]);
            mp[pair[1]].insert(pair[0]);
        }
        
        for(int i = 0;i<n;i++) {
            string& s1=sentence1[i], &s2=sentence2[i];
            if(s1==s2 || mp[s1].find(s2) !=  mp[s1].end())continue;
            return false;
        }
        
        return true;
    }

    bool areSentencesSimilar_v01(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int n = sentence1.size();
        if(n!=sentence2.size()) 
            return false;
        
        unordered_map<string,unordered_set<string>> mp;
        for(auto &pair:similarPairs) {
            mp[pair[0]].insert(pair[1]);
            mp[pair[1]].insert(pair[0]);
        }
        
        function<bool(string&,string&)>similar = [&](string &s1, string &s2){
            if(s1==s2) return true;
            if(mp[s1].find(s2) !=  mp[s1].end()) return true;
            if(mp[s2].find(s1) !=  mp[s2].end()) return true;
            return false;
        };
        
        for(int i = 0;i<n;i++) 
            if(!similar(sentence1[i],sentence2[i])) 
                return false;        
        return true;
    }
};