class Solution {
    //https://leetcode.com/problems/print-words-vertically
public:
    vector<string> printVertically(string s) {
        vector<string> v={""};
        for(auto &c:s) 
            if(c==' ') 
                v.push_back("");
            else
                v.back().push_back(c);
        int m = v.size(), n=0;
        for(auto &s:v) n = max(n, (int)s.length());
        vector<string> w = vector<string>(n, string(m,' '));
        for(int i = 0; i<m; i++) 
            for(int j = 0; j<(int)v[i].length(); j++) 
                w[j][i] = v[i][j];
        for(auto &s:w) while(s.back()==' ')s.pop_back();        
        return w;
    }
};