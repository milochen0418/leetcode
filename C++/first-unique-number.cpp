class FirstUnique {
public:
    unordered_map<int,int> mp_cnt;//value to counter of the appearing of it.
    queue<int> q;
    
    FirstUnique(vector<int>& nums) {
        for(auto &i:nums) {
            mp_cnt[i]++; 
            q.push(i);
        }
    }
    
    int showFirstUnique() {
        while(!q.empty()) {
            int e = q.front();
            if(mp_cnt[e]==1) return e;
            q.pop();
        }
        return -1;        
    }
    
    void add(int value) {
        q.push(value);
        mp_cnt[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */