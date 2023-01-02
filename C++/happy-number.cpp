class Solution {
    //https://leetcode.com/problems/happy-number
public:
    typedef unsigned long long ull;
    bool isHappy(int n) {
        unordered_set<ull> ss;
        ull sum = n;
        do {
            ss.insert(sum);
            n = sum;
            sum = 0;
            while(n>0) {
                int d = n%10;
                sum+=d*d;
                n/=10;
            }
        } while(ss.find(sum) == ss.end());
        return sum == 1;
    }
    
    bool isHappy_v01(int n) {
        unordered_set<int> s;
        while(s.find(n)==s.end()) {
            if(n==1) return true;
            s.insert(n);
            n = next(n);    
        }
        return false;
    }
    int next(int n) {
        int sum = 0;
        while(n>0) {
            int i = n%10;
            sum+=(i*i);
            n /=10;
        }
        return sum;
    }
};