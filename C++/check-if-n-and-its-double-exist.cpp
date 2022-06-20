class Solution {
    //https://leetcode.com/problems/check-if-n-and-its-double-exist/
public:
    bool checkIfExist(vector<int>& arr) {
        vector<int> &a = arr;
        sort(a.begin(), a.end());
        int n = a.size();
        int zero_cnt=0;
        for(auto &t:a) zero_cnt+=(t==0);
        for(auto &t:a) {
            if(t==0) {
                if(zero_cnt>1) return true;
                continue; //processing zero case
            }
            int L = 0, R=n-1;
            while(L<=R) {
                int M = L+(R-L)/2;
                if(a[M]==2*t) return true;
                if(a[M] < 2*t) L=M+1; else R=M-1;
            }
        }
        return false;
    }

    bool checkIfExistByHashSet(vector<int>& arr) {
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