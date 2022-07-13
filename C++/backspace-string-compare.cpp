class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
    }

    bool backspaceCompareVer01ByVector(string s, string t) {
        vector<char> sv;
        vector<char> tv;
        for(auto &c:s) {
            if(c=='#') {
                if(!sv.empty())sv.pop_back();
            } else {
                sv.push_back(c);
            }
        }
        for(auto &c:t) {
            if(c=='#') {
                if(!tv.empty())tv.pop_back();
            } else {
                tv.push_back(c);
            }
        }
        return sv == tv;
    }
};