class Solution {
    //https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string
public:
    string removeDuplicates(string s) {
        string ans;
        for(auto &c: s) 
            if(ans.length()==0 || ans.back() != c) 
                ans.push_back(c);
            else 
                ans.pop_back();    
        return ans;
    }
};