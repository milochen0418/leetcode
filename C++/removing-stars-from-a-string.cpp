    
class Solution {
    //https://leetcode.com/problems/removing-stars-from-a-string/
public:

    string removeStars(string str) {
        /*
        Input: s = "leet**cod*e"
        Output: "lecoe"
            lecoe
        bottom       top

        ans = "eocel"
        -> reverse -> "lecoe"
        */

        stack<char> s;
        for(auto &c:str) {
            if(c=='*') {
                if(!s.empty()) s.pop();
            } else {
                s.push(c);
            }
        }
        
        
        string ans="";
        while(!s.empty()) {
            char c = s.top();
            s.pop();
            ans.push_back(c);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};