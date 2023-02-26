class Solution {
    //https://leetcode.com/problems/unique-email-addresses
    //article https://leetcode.com/problems/unique-email-addresses/discuss/3233164/C%2B%2B-One-Pass-O(N)-12-lines
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> set;
        for(auto &s:emails) {
            string r;
            int i = 0, n = s.length();
            while(s[i]!='@' ) 
                if(s[i]=='+') while(s[i]!='@') i++;
                else if(s[i]!='.') r.push_back(s[i++]);    
                else i++;
            while(i<n) r.push_back(s[i++]);            
            set.insert(r);
        }
        return set.size();
    }

    int numUniqueEmails_v01(vector<string>& emails) {
        unordered_set<string> set;
        function<string(string&)> convert = [](string &s) {
            string r;
            int i = 0, n = s.length();
            while(s[i]!='@' ) {
                if(s[i]=='+') {
                    while(s[i]!='@') i++;
                    break;
                } else if(s[i]!='.'){
                    r.push_back(s[i++]);    
                } else {
                    i++;
                }
            }
            while(i<n) r.push_back(s[i++]);
            return r;
        };
        for(auto &email:emails) set.insert(convert(email));
        return set.size();
    }    
};