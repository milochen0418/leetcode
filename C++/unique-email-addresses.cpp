class Solution {
    //https://leetcode.com/problems/unique-email-addresses
public:
    int numUniqueEmails(vector<string>& emails) {
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