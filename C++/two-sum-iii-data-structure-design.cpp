class TwoSum {
    //https://leetcode.com/problems/two-sum-iii-data-structure-design
    //article https://leetcode.com/problems/two-sum-iii-data-structure-design/discuss/2963424/C%2B%2B-or-O(1)-find
public:
    unordered_set<int> twosum_set;
    unordered_set<int> s;
    TwoSum() {
        
    }
    
    void add(int number) {
        if(s.find(number)==s.end()) {
            for(auto &i:s) twosum_set.insert(number+i);
            s.insert(number);
        } else {
            twosum_set.insert(2*number);
        }
    }
    
    bool find(int value) {
        return twosum_set.find(value)!=twosum_set.end();
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */