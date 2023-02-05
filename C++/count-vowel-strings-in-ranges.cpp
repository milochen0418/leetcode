class Solution {
    //https://leetcode.com/problems/count-vowel-strings-in-ranges
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> is_vowel = vector<int>(256,0);
        is_vowel['a']=is_vowel['e']=is_vowel['i']=is_vowel['o']=is_vowel['u']=1;
        vector<int> v = vector<int>(words.size(),0);
        for(int i = 0; i < v.size();i++){
            string &w = words[i];
            if(is_vowel[w[0]]==1 && is_vowel[w[w.length()-1]]==1) {
                v[i] = 1;
            }
        }
        
        //prefix sum
        int n = v.size();
        for(int i =1;i<n;i++) {
            v[i] =v[i] + v[i-1];
        }
        
        //1,2,3,4
        //[0..]
        vector<int> ans;
        for(auto &q:queries) {
            int start = q[0];
            int end = q[1];
            int v1 = start==0?0:v[start-1];
            int v2 = v[end];
            ans.push_back(v2-v1);
        }
        return ans;
        
    }
};