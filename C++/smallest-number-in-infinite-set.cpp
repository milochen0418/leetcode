class SmallestInfiniteSet {
    //https://leetcode.com/problems/smallest-number-in-infinite-set
public:
    int minv = 1;
    //unordered_set<int> s;
    vector<int> s;
    SmallestInfiniteSet() {
        s = vector<int>(1001,0);
    }
    
    int popSmallest() {
        //while(s.find(minv) != s.end()) minv++;
        while(s[minv]==1) minv++;
        //s.insert(minv);
        s[minv]=1;
        int ret = minv++;
        return ret;
    }
    
    void addBack(int num) {
        //if(s.find(num) != s.end()) {
        if(s[num]==1) {
            //s.erase(num);
            s[num]=0;
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