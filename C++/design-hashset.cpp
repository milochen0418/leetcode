class MyHashSet {
public:
    vector<bool> hash_table;
    MyHashSet() {
        hash_table = vector<bool>(1000001, false);
    }
    
    void add(int key) {
        hash_table[key] = true;
    }
    
    void remove(int key) {
        hash_table[key] = false;
    }
    
    bool contains(int key) {
        return hash_table[key] == true;
    }
};


/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */