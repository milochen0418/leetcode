class SmallestInfiniteSet {
    //https://leetcode.com/problems/smallest-number-in-infinite-set
public:
    int minv = 1;
    unordered_set<int> s;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        while(s.find(minv) != s.end()) minv++;
        s.insert(minv);
        int ret = minv++;
        return ret;
    }
    
    void addBack(int num) {
        if(s.find(num) != s.end()) {
            s.erase(num);
            if(num<minv) minv=num;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */