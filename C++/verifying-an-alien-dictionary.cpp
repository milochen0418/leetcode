class Solution {
    //https://leetcode.com/problems/verifying-an-alien-dictionary
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<char> mp = vector<char>(256,0);
        for(int i = 0; i<order.length();i++) 
            mp[order[i]] = i+'a';
        
        for(auto &w:words)
            for(auto &c:w) 
                c = mp[c];
        
        for(int i = 1; i < words.size();i++) 
            if(words[i] < words[i-1]) 
                return false;
        
        return true;
    }
};