class Solution {
    //https://leetcode.com/problems/goat-latin
public:
    string toGoatLatin(string sentence) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u','A','E','I','O','U'};
        vector<vector<int>> v;
        int i = 0, n = sentence.length();
        while(i<n) {
            while(i<n && sentence[i] == ' ')i++;
            if(i>=n) break;
            int j = i;
            while(j<n && sentence[j] != ' ')j++;
            v.push_back({i,j-1}); //collect the substring [i..j-1] as each word in the sentence. 
            i=j;
        } 

        string ans="";
        int acnt = 2;
        for(auto &w:v) {            
            int p = vowels.find(sentence[w[0]]) == vowels.end()?1:0;
            int m = w[1] - w[0] + 1;
            for(int i = 0; i<m ;i++) ans.push_back(sentence[ w[0]+ ((i+p)%m)]);
            ans.push_back('m');
            for(int i = 0; i<acnt;i++) ans.push_back('a');
            ans.push_back(' ');
            acnt++;
        }
        ans.pop_back();
        return ans;
    }
};