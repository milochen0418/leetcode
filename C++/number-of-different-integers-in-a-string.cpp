class Solution {
    //https://leetcode.com/problems/number-of-different-integers-in-a-string/
    //article https://leetcode.com/problems/number-of-different-integers-in-a-string/discuss/2950232/C%2B%2B-or-O(N)
public:
    int numDifferentIntegers(string word) {
        int n = word.length();
        unordered_set<string> ss;
        string s = "";
        for(int i = 0;i<n+1;i++) {
            char c = i==n?'z':word[i];
            if('9'>=c && c>='0') {
                s.push_back(c);    
            } else {
                if(i>0) {
                    if(s.length()>0) {
                        ss.insert(process(s));
                    }
                }
                s="";
            }
        }
        return ss.size();
        
    }
    string process(string& s) {
        //delete prefix zero
        string ret;
        int n = s.length();
        int i=0;
        
        while(i<n && s[i]=='0')i++;
        if(n>=1 && i>=n) return "0";
        for(int j = i;j<n;j++) {
            ret.push_back(s[j]);
        }
        return ret;
    }
};