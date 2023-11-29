class Solution {
    //https://leetcode.com/problems/find-words-containing-character
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int n = words.size();
        for(int i = 0;i<n;i++) 
            for(auto &c:words[i])
                if(c==x) {
                    ans.push_back(i);
                    break;
                }
        return ans;
    }
};