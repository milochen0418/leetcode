class Solution {
    //https://leetcode.com/problems/remove-duplicate-letters
    //article https://leetcode.com/problems/remove-duplicate-letters/discuss/1861190/C%2B%2B-or-deque-or-Time-O(n)-Space-O(n)
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5163581546997628/
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
        unordered_map<char,int> in_stack_mp;//in_stack_mp[i]==1 iff char i in deque
        deque<int> q; 
        
        int n = s.length();
        for(int i = 0; i<n; i++) mp[s[i]] = i;
        
        for(int i = 0; i<n; i++){ 
            char c = s[i];
            if(in_stack_mp[c]==0){
                while(!q.empty() && c<q.back() && mp[q.back()]>i) {
                    in_stack_mp[q.back()]=0;
                    q.pop_back();
                }
                in_stack_mp[c] = 1;
                q.push_back(c);
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
"acbac"
*/