class Allocator {
    //https://leetcode.com/problems/design-memory-allocator
public:
    vector<int> v;
    Allocator(int n) {
        v = vector<int>(n,-1);
    }
    
    int allocate(int size, int mID) {
        int w = 0,n=v.size();
        int start = -1;
        for(int i = 0; i <n;i++) {
            if(v[i]<0) {
                if(start == -1) start = i;
                w++;
                if(w>=size) {
                    for(int j=0;j<w;j++) {
                        v[j+start] = mID;
                    }
                    return start;
                }
            } else {
                start = -1;
                w=0;
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int cnt = 0;
        for(int i = 0;i<v.size();i++) {
            if(v[i] == mID) {
                v[i] = -1;
                cnt++;
            }
        }
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */