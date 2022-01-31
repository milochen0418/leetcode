class Solution {
public:
    
    vector<vector<string>> groupStringsOld4(vector<string>& strings) {                
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
    vector<vector<string>> groupStringsOld3(vector<string>& strings) {
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

    int extractInt(string& s) {
        long hash = s.length();
        for(int i=0;i<s.length()-1;i++) {
            int val = (26+s[i]-s[i+1])%26;
            hash ^= (val + 0x9e3779b9 + (hash << 6) + (hash >> 2)) % INT_MAX;
        }        
        return hash;
    }
    
    vector<vector<string>> groupStringsOld2(vector<string>& strings) {
        //return groupStringsOld2(strings);Old1
        unordered_map<int, vector<string>> mp;
        for(auto& s: strings) {
            int vi = extractInt(s);
            mp[vi].push_back(s);
        }        
        vector<vector<string>> result;
        for(auto& [key,v]: mp) result.push_back(v);
        return result;
    }
    
    vector<vector<string>> groupStringsOld1(vector<string>& strings) {
        //return groupStringsOld2(strings)
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<strings.size();i++) {        
            int vi = extractInt(strings[i]);
            mp[vi].push_back(i);
        }
        
        vector<vector<string>> result;
        for(auto& [key,v]: mp) {
            vector<string> vs(v.size());
            for(int i=0;i<v.size();i++) {
                vs[i]=strings[v[i]];
            }   
            result.push_back(vs);
        }
        return result;
    }
    
    vector<vector<string>> groupStrings(vector<string>& strings) {
        //return groupStringsOld1(strings)
        unordered_map<int,int> mp;
        vector<vector<string>> result;
        int cnt=0;
        for(int i=0;i<strings.size();i++) {
            int vi = extractInt(strings[i]);
            if(mp.find(vi)==mp.end()) {
                mp[vi]=cnt++;
                result.push_back(vector<string>());
            }
            result[mp[vi]].push_back(strings[i]);
        }
        return result;
    }  
};