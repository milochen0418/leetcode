class Solution {
    //https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones
public:
    bool checkOnesSegment(string s) {
        string ss;
        int cnt1=0;
        for(auto &c:s) 
            if(ss.empty() || ss.back() != c){
                if(c=='1')cnt1++;
                if(cnt1>=2) return false;
                ss.push_back(c);
            } 
        return cnt1==1;
    }
};