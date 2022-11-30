class RandomizedSet {
    //https://leetcode.com/problems/insert-delete-getrandom-o1
    //article https://leetcode.com/problems/insert-delete-getrandom-o1/discuss/2861368/C%2B%2B-or-hash-map-or-explanation
public:
    
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