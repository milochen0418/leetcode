class Solution {
    //https://leetcode.com/problems/remove-duplicate-letters
public:
    //    .
    //cbacdcbc ,  
    //c
    //b
    //a
    //ac
    //acd
    //acdb
    //deque<int> gquiz; 
    // https://www.geeksforgeeks.org/deque-cpp-stl/
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> mp;//char to maximum index
        unordered_set<char> hset;
        stack<char> stk;
        deque<int> q;
        set<char> ss;
        int n = s.length();
        for(int i = 0; i<n; i++) mp[s[i]] = i;
        
        for(int i = 0; i<n; i++){ 
            char c = s[i];
            if(q.empty()) {
                q.push_back(c);
                ss.insert(c);
            } else if(c>q.back()) {
                if(ss.find(c) == ss.end()) {
                    q.push_back(c);
                    ss.insert(c);
                }
            } else if(c<q.back()) {
                if(mp[q.back()]>i) {
                    while(!q.empty() && mp[q.back()]>i) {
                        ss.erase(q.back());    
                        q.pop_back();
                    }
                    q.push_back(c);
                    ss.insert(c);
                } else {
                    if(ss.find(c) == ss.end()) {
                        q.push_back(c);
                        ss.insert(c);
                    }
                }
            }
        }
        string ans="";
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop_front();
        }
        return ans;
        
        return "";
    }
};
        
/* testcase
"bcb"
"bcabc"
"ccacbaba"
 */