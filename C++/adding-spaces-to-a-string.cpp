class Solution {
    //https://leetcode.com/problems/adding-spaces-to-a-string
public:
    string addSpaces(string s, vector<int>& spaces) {
        int j = 0, i = 0, n = s.length();
        string ans;
        for(int i = 0; i<n; i++) {
            if(j<spaces.size() && i==spaces[j]) {
                ans.push_back(' ');
                j++;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};