class Solution {
    //https://leetcode.com/problems/check-if-n-and-its-double-exist/
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        int zero_cnt = 0;
        for(auto& i:arr) 
            if(i==0) 
                zero_cnt++;
            else 
                s.insert(i);
        for(auto& i:s) 
            if(s.find(i*2) != s.end()) 
                return true;
        return zero_cnt>=2;
    }
};