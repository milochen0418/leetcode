class TimeMap {
    //https://leetcode.com/problems/time-based-key-value-store
public:
    //#define DEBUG
    #ifndef DEBUG
        #define printf(...) empty_printf(__VA_ARGS__)
    #endif 
    #define empty_printf(...)
    #define print_container(name) printf("%s = ",#name);for(auto &i:name)printf("%d,",i);printf("\n");
    
    unordered_map<string, vector<int>> tsv; //Use key to get time-stamp vector
    unordered_map<string, unordered_map<int, string>> tsm;//Use key to get time-stamp map ;
    TimeMap() {
        printf("\n");
    }
    
    void set(string key, string value, int timestamp) {
        if(tsv.find(key) == tsv.end()) {
            tsv[key].push_back(0);
            tsm[key][0] = "";
        }
        tsv[key].push_back(timestamp);
        tsm[key][timestamp]=value;
        
        printf("key = %s -> ", key.c_str());
        print_container(tsv[key]);
        for(auto &i:tsv[key]) 
            printf("\"%s\",", tsm[key][i].c_str());
        printf("\n");
        
    }
    
    
    string get(string key, int timestamp) {
        if(tsv.find(key) == tsv.end()) return "";
        vector<int>& v = tsv[key];
        unordered_map<int, string> mp = tsm[key];
        if(timestamp >= v.back()) return mp[v.back()];
        int n = v.size(), L=0, R=n-1;
        int M=0;
        int t = timestamp;
        while(L<=R) {
            M = L+ (R-L)/2;
            if(t>=v[M] && (M+1>=n|| t<v[M+1]))  {
                //M is solution
                break;
            }
            if(t>=v[M]) {//t>=tsv[M+1] too
                //M should move to right
                L=M+1;
            } else {
                R=M-1;
            }      
        }
        printf("final L,M,R = %d,%d,%d\n", L, M, R);
        
        return  mp[v[M]];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */