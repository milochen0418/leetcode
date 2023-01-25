class Solution {
    //https://leetcode.com/problems/uncommon-words-from-two-sentences
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        //invalid test case is string is like " this apple is sweet" or "this apple is sweet "
        function<void(string&, unordered_map<string,int>&)> get_words = [&](string& s1, unordered_map<string,int>& s1map) {
            string s;
            for(int i = 0; i <= (int)s1.length();i++) {
                if(i<(int)s1.length() &&  s1[i]!=' ') {
                    s.push_back(s1[i]);
                    continue;
                }
                s1map[s]++;
                s="";
            }
        };
        unordered_map<string,int> s1mp;
        unordered_map<string,int> s2mp;
        get_words(s1, s1mp);
        get_words(s2, s2mp);
        vector<string> ans;
        for(auto &[word,cnt]:s1mp) 
            if(cnt==1 && s2mp.find(word)==s2mp.end() ) 
                ans.push_back(word);
        for(auto &[word,cnt]:s2mp) 
            if(cnt==1 && s1mp.find(word)==s1mp.end() ) 
                ans.push_back(word);
        return ans;
    }
};