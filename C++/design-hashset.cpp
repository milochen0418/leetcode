class MyHashSet {
    //https://leetcode.com/problems/design-hashset
public:
    const int n = 1000000 + 1;
    vector<bool> a = vector<bool>(n,false);
    MyHashSet() {
    }
    
    void add(int key) {
        a[key] = true;
    }
    
    void remove(int key) {
        a[key] = false;
    }
    
    bool contains(int key) {
        return a[key];
    }
};


/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */