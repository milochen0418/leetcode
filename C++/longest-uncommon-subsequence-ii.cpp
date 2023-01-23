class Solution {
    //https://leetcode.com/problems/longest-uncommon-subsequence-ii/
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        vector<bool> failed = vector<bool>(n,false);
        unordered_set<string>failed_strs;
        unordered_set<string>observed_strs;
        int maxv=0;
        for(int i = 0;i<n;i++) {
            string &s1=strs[i];
            for(auto&s2:strs){
                if(&s1!=&s2 && s1==s2) {
                    failed[i] = true;
                    failed_strs.insert(strs[i]);
                    break;
                }
            }
            if(failed[i] == false) observed_strs.insert(strs[i]);
        }
        
        unordered_set<string> new_observed_strs;
        
        while(!observed_strs.empty()) {        
            new_observed_strs = observed_strs;
            for(auto &s:observed_strs) {
                for(auto &fs:failed_strs) {
                    if(find_subsequence(fs, s)) {
                        new_observed_strs.erase(s);
                    }
                }
            }
            if(new_observed_strs.size() == observed_strs.size()) break;
            observed_strs = new_observed_strs;
        }
        
        if(new_observed_strs.empty()) return -1;
        for(auto&s:new_observed_strs) 
            maxv = max(maxv,(int)s.length());
        return maxv;
    }
    
    //Check the string B is subsequence of A or not.
    bool find_subsequence(const string &A, const string &B)  {
        //If the string B cannot not be composed from any subsequence of A,
        //then return false;
        int i=0;
        
        for(auto& c:A) {
            if(c==B[i])i++;
            if(i>=B.length())break;
        }
        if(i>=B.length()) return true;
        
        return false;
    }
};