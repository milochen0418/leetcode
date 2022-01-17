class Solution {
    //https://leetcode.com/problems/maximum-number-of-words-you-can-type
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> strs;
        stringstream ss(text);
        string segment;
        while(getline(ss, segment,' ')) {
            strs.push_back(segment);
        }
        const char* c_letters = brokenLetters.c_str();
        unordered_set brokenset(c_letters, c_letters+brokenLetters.size());//set of borken letters
        int success_count = strs.size();
        for (auto word: strs) {
            const char* str = word.c_str();
            int len = word.size();
            for(int i=0;i<len;i++) {
                if( brokenset.count(str[i]) == 0) {
                    //str[i] is not in brokenset
                    continue;
                } else {
                    success_count -= 1;
                    break;
                }
            }            
        }
        return success_count;
    }
};