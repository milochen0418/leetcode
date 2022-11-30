class RandomizedSet {
    //https://leetcode.com/problems/insert-delete-getrandom-o1
public:
    /* Refer time complexity of hash set here
    https://www.geeksforgeeks.org/hashset-in-java/ 
    
    Time Complexity of HashSet Operations: The underlying data structure for HashSet is hashtable. So amortize (average or usual case) time complexity for add, remove and look-up (contains method) operation of HashSet takes O(1) time.
    */
    
    unordered_map<int,int> mp;
    vector<int> v;
    
    RandomizedSet() { }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        v.push_back(val);
        mp[val] = v.size()-1;
        return true;        
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int vv=v[v.size()-1];
        swap(v[v.size()-1], v[mp[val]]);
        mp[vv] = mp[val]; 
        mp.erase(val);
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */