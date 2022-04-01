class Solution {
    //https://leetcode.com/problems/brace-expansion
    //article https://leetcode.com/problems/brace-expansion/discuss/1902830/C%2B%2B-or-counter-approach-best-time-O(N*26N)-with-space-O(N*26N)-or-no-DFS-no-backtracking
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5199814613374321/
public:
    vector<string> expand(string s) {
        int n = s.length();
        vector<vector<char>> v;
        vector<string> ans;
        for(int i = 0;i<n;i++) {
            if(s[i]=='{') {
                ++i;
                vector<char> vc; 
                while(s[i]!='}') {
                    if(s[i]!=',') vc.push_back(s[i]);
                    i++;
                }
                v.push_back(vc);
            } else {
                vector<char> vc;
                vc.push_back(s[i]);
                v.push_back(vc);
            }
        }
        int m = 1;
        n = v.size();
        vector<int> idx(n,0);
        
        for(int i = 0; i < n;i++) {
            sort(v[i].begin(), v[i].end());
            m*=v[i].size();
        }
        
        int i = 0;
        while(i<m) {
            string str = string(n,'\0');
            for(int j = 0; j<n;j++) { 
                str[j]=v[j][idx[j]];
            }
            ans.push_back(str);
            i++;
            for(int j=n-1;j>=0;j--) {
                if( (idx[j]+1) % v[j].size() != 0) {
                    idx[j]++; 
                    break;
                } else {
                    idx[j] = 0;   
                }
            }
        }        
        return ans;
    }
};