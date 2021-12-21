class Logger {
public:
    
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(umap.find(message) != umap.end() ) {
            int prev_timestamp = umap[message];
            if(timestamp - prev_timestamp >= 10) { 
                umap[message] = timestamp;
                return true;
            } else {
                return false; 
            }
            
        } else { 
            umap[message] = timestamp;
            return true;
        }
        
    }
private: 
    unordered_map<string, int> umap;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */