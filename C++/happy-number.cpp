class Solution {
    //https://leetcode.com/problems/happy-number
public:
    bool isHappy(int n) {
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