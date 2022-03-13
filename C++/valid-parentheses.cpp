class Solution {
    //https://leetcode.com/problems/valid-parentheses
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char,char> mp = {{')','('},{']','['},{'}','{'}};
        unordered_set<char> hset= {'(','[','{'};
        for(auto& i:s) { 
            if(hset.find(i) != hset.end()) {
                stk.push(i);
            } else {
                if(stk.empty()) return false;
                if(mp[i]!=stk.top()) return false;
                stk.pop();
            }    
        }
        return stk.empty()==true;
    }
};