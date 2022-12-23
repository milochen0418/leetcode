class Solution {
    //https://leetcode.com/problems/sorting-the-sentence
    //https://leetcode.com/problems/sorting-the-sentence/discuss/2942483/C%2B%2B-or-simple-17-lines-O(N)
public:
    string sortSentence(string s) {
        int n = s.length();
        vector<int> mp = vector<int>(10,-1);
        for(int i = n-1;i>=0;i--) {
            if('1'<=s[i] && s[i]<='9') {
                int tmp = i;
                while(i>=0 && s[i]!=' ')i--;
                mp[s[tmp]-'0'] = i+1;
            }
        }
        string ans;
        for(int i=1; i<=9; i++) {
            int j = mp[i];
            if(j==-1) break;
            if(i!=1)ans.push_back(' ');
            while(!('0'<=s[j] && s[j]<='9')) ans.push_back(s[j++]);
        }
        return ans;
    }
};