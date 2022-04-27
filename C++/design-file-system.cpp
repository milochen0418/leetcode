class FileSystem {
    //https://leetcode.com/problems/design-file-system
public:
    unordered_map<string, int> mp;
    FileSystem() {
        
    }
    
    bool isLegal(string path) {
        
        int n = path.length();
        string &s = path;
        int i = 0;
        while(i < n && s[i] == '/' ) {
            if(i+1>=n) return false;
            if(s[i+1]=='/') return false;
            while(i<n) {
                i++;
                if(s[i]=='/') break;
            }
        }
        return true;
    }
    bool createPath(string path, int value) {
        //printf("path=%s\n", path.c_str());
        if(!isLegal(path)) {
            printf("not isLegal(%s)\n", path.c_str());
            return false;
        }
        //printf("path=%s\n", path.c_str());
        if(mp.find(path) != mp.end()) {
            return false;
        }
        string base_path = getBasePath(path);
        if(base_path == "") {
            mp[path] = value;
            //printf("basepath = %s, createPath(%s)\n", base_path.c_str(), path.c_str());
        } else {
            //if(mp[base_path] == 0) {
            if(mp.find(base_path) == mp.end()) {
                return false;
            }
            mp[path] = value;
            //printf("createPath(%s)\n", path.c_str());
        }
        
        return true;
    }
    string getBasePath(string path) {
        int n = path.length();
        int last_slash_idx = 0;
        for(int i = n-1; i>=0;i--){
            if(path[i] == '/') {
                last_slash_idx = i;
                break;
            }
        }
        return path.substr(0,last_slash_idx);        
    }
    
    int get(string path) {
        if(mp.find(path) == mp.end() ) {
            return -1;  
        } else {
            return mp[path];    
        }
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */