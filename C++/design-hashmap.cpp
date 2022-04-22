class MyHashMap {
public:
    const int n = 1000000+1;
    vector<int> a = vector<int>(n,-1);
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        a[key] = value;    
    }
    
    int get(int key) {
        return a[key];
    }
    
    void remove(int key) {
        a[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */