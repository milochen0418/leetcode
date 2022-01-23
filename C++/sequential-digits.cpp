class Solution {
    //https://leetcode.com/problems/sequential-digits/
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v; 
        int test_val = 93241;
        int maxd = 1; 
        int inc = 1;
        int base = 1;
        int i=2;
        while(test_val/(maxd*10)>0) {
            maxd*=10;
            inc=(inc*10)+1;
            base = base*10+i;
            i++;
        }
        v.push_back(maxd);
        v.push_back(inc);
        v.push_back(base);
        v.push_back(-1);
        for (int i = 0; i<(10-base%10); i++) {
            v.push_back(inc*i+base);
        }
        return v;
    }
};