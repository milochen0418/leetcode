class Solution {
    //https://leetcode.com/problems/remove-vowels-from-a-string
public:
    string removeVowels(string s) {
        vector<int> v=vector<int>(256,0);
        v['a']=v['e']=v['i']=v['o']=v['u']=1;
        string ans;
        for(auto &c:s) if(!v[c]) ans.push_back(c);
        return ans;
    }
};