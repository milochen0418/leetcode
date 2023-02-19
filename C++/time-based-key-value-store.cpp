class TimeMap {
    //https://leetcode.com/problems/time-based-key-value-store
public:
    
    unordered_map<string, vector<int>> tsv; //Use key to get time-stamp vector
    unordered_map<string, vector<string>> tsm;//Use key to get time-stamp map ;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        if(tsv.find(key) == tsv.end()) {
            tsv[key].push_back(0);
            tsm[key].push_back("");
        }
        tsv[key].push_back(timestamp);
        tsm[key].push_back(value);
    }
    
    
    string get(string key, int timestamp) {
        if(tsv.find(key) == tsv.end()) return "";
        const vector<int>& v = tsv[key];
        const vector<string>& mp = tsm[key];
        if(timestamp >= v.back()) return mp.back();
        int n = v.size(), L=0, R=n-1;
        int M=0;
        int t = timestamp;
        while(L<=R) {
            M = L+ (R-L)/2;
            if(t>=v[M] && (M+1>=n|| t<v[M+1]))  break;
            if(t>=v[M]) 
                L=M+1;
            else 
                R=M-1;
        }        
        return mp[M];
    }
};

