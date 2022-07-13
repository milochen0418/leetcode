class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stk1, stk2;
        for(auto &c: s)
            if(c!='#') 
                stk1.push(c);
            else 
                if(!stk1.empty())stk1.pop();
        
        for(auto &c: t) 
            if(c!='#') 
                stk2.push(c);
            else 
                if(!stk2.empty())stk2.pop();
        
        while( !(stk1.empty() || stk2.empty()) ){
            if( stk1.top() != stk2.top()) return false;
            stk1.pop();
            stk2.pop();
            //printf("stk1.size() = %d, stk2.size()=%d\n", (int)stk1.size(), (int)stk2.size());
        }
        return stk1.empty() && stk2.empty();

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