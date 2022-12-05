class Solution {
    //https://leetcode.com/problems/find-resultant-array-after-removing-anagrams
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> awords = words;
        for(auto &s:awords) sort(s.begin(), s.end());
        vector<int> selectedIdice;
        string tmp=awords[0];
        selectedIdice.push_back(0);
        for(int i = 1;i<awords.size();i++) {
            if(tmp != awords[i]) {
                selectedIdice.push_back(i);
                tmp = awords[i];
            }
        }
        vector<string> ans;
        for(auto&idx:selectedIdice) ans.push_back(words[idx]);
        return ans;
    }
};