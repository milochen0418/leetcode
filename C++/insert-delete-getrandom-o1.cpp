class RandomizedSet {
public:
    /* Refer time complexity of hash set here
    https://www.geeksforgeeks.org/hashset-in-java/ 
    
    Time Complexity of HashSet Operations: The underlying data structure for HashSet is hashtable. So amortize (average or usual case) time complexity for add, remove and look-up (contains method) operation of HashSet takes O(1) time.
    */
    unordered_set<int> s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.find(val) == s.end()) {
            s.insert(val);
            return true;
        } else {
            return false;
        }
        
    }
    
    bool remove(int val) {
        if(s.find(val) != s.end()) {
            s.erase(val);
            return true;
        } else {
            return false;
        }
    }
    
    int getRandom() {
        //TODO
        return rand()%s.size();
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */