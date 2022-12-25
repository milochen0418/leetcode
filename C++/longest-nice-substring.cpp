class Solution {
    //https://leetcode.com/problems/longest-nice-substring
    //article https://leetcode.com/problems/longest-nice-substring/discuss/2950367/C%2B%2B-or-brute-force
public:
    string longestNiceSubstring(string s) {
        //vector<int> Av = vector<int>(26,0), av = Av;
        int maxv = 0, n = s.length();
        string ans;
        
        for(int i = 0;i<n;i++) {
            for(int j=i;j<n;j++) {
                vector<int> Av = vector<int>(26,0), av = Av;
                string candidate = "";
                for(int k = i; k<=j;k++) {
                    if('Z'>=s[k] && s[k]>='A') 
                        Av[s[k]-'A']++;
                    else 
                        av[s[k]-'a']++;
                    candidate.push_back(s[k]);
                }
                if(isNice(av,Av)) {
                    int len=j-i+1;
                    //ans = max(ans, j-i+1);
                    if(len>maxv) {
                        ans = candidate;
                        maxv = len;
                    }
                }
            }
        }
        return ans;
    }
    bool isNice(vector<int>&av, vector<int>&Av) {
        for(int i = 0; i<26;i++) {
            if(av[i]!=0 && Av[i]==0) return false;
            if(av[i]==0 && Av[i]!=0) return false;
        }
        return true;
    }
};