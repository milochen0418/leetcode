class Solution {
    //https://leetcode.com/problems/number-of-even-and-odd-bits/
public:
    vector<int> evenOddBit(int n) {
        string bin = "";
        vector<int> ans = {0,0};
        while(n>0) {
            bin.push_back((n%2)+'0');
            n/=2;
        }
        for(int i = 0; i<bin.length();i++) {
            if(bin[i]=='1') ans[i%2]++;
        }
        return ans;
    }
};