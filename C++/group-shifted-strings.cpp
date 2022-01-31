class Solution {
    //https://leetcode.com/problems/group-shifted-strings/
public:
    
    vector<vector<string>> groupStringsOld(vector<string>& strings) {                
        unordered_map<vector<int>,vector<string>,vector_hasher> mp;
        for(auto& s: strings) {
            vector<int> vs = extract(s);
            mp[vs].push_back(s);
        }        
        vector<vector<string>> result;
        for(auto& [key,v]: mp) result.push_back(v);
        return result;
    }
    
    
    struct vector_hasher {
        int operator()(const vector<int> &V) const {
            long hash = V.size();
            for(auto &i : V) {
                hash ^= (i + 0x9e3779b9 + (hash << 6) + (hash >> 2)) % INT_MAX;
            }
            return hash;
        }
    };
    
    vector<int> extract(string s) {
        int len = s.length();
        vector<int> v(len);
        v[0]=len;
        for(int i=1;i<s.length();i++) {
            v.push_back( (26+s[i-1]-s[i])%26 ) ;
        }
        return v;
    }
    
    string extractStr(string s) {
        //string r(s.length()-1);
        string r(s.length()-1, ' ');
        for(int i=1;i<s.length();i++) {
            r[i-1] = (26+s[i-1]-s[i])%26;
        }
        return r;
    }
    
    vector<vector<string>> groupStrings(vector<string>& strings) {
        //return groupStringsOld(strings);
        unordered_map<string, vector<string>> mp;
        for(auto& s: strings) {
            string vs = extractStr(s);
            mp[vs].push_back(s);
        }        
        vector<vector<string>> result;
        for(auto& [key,v]: mp) result.push_back(v);
        return result;
    }
};