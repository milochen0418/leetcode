class Solution {
    //https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence
public:
    bool areNumbersAscending(string s) {
        vector<int> v;
        s.push_back('.');
        string d;
        for(auto &c:s) {
            if('0'<=c  && c<='9') {
                d.push_back(c);
            } else {
                if(d!="") {
                    v.push_back(stoi(d));
                    d="";
                }
            }
        }
        if(v.size()<=1) return true;
        for(int i = 1;i<v.size();i++) {
            if(v[i-1]>=v[i]) return false;
        }
        return true;
    }
};