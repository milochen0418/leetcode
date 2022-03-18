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
        unordered_map<char,int> in_stack_mp;
        deque<int> q;
        int n = s.length();
        for(int i = 0; i<n; i++) mp[s[i]] = i;
        
        for(int i = 0; i<n; i++){ 
            char c = s[i];
            
            if(q.empty()) {
                q.push_back(c);
                in_stack_mp[c]=1;
            } else if(c>q.back()) {
                if(in_stack_mp[c]==0) {
                    q.push_back(c);
                    in_stack_mp[c]=1;
                }
            } else if(c<q.back()) {
                if(mp[q.back()]>i) {
                    while(!q.empty() && mp[q.back()]>i) {
                        in_stack_mp[q.back()]=0;
                        q.pop_back();
                    }
                    q.push_back(c);
                    in_stack_mp[c]=1;
                } else {
                    if(in_stack_mp[q.back()]==0) {
                        q.push_back(c);
                        in_stack_mp[c]=1;
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