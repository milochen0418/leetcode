class OrderedStream {
    //https://leetcode.com/problems/design-an-ordered-stream
public:
    int n;
    int idx;
    vector<string> vs;
    OrderedStream(int _n) {
        n = _n;
        idx = 1;
        vs = vector<string>(n+1, "");
    }
    
    vector<string> insert(int idKey, string value) {
        vs[idKey] = value;
        vector<string> played = vector<string>();
        if(idKey == idx) {
            while(idx<=n && vs[idx].length()>0) played.push_back(vs[idx++]);  
        }
        return played;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */