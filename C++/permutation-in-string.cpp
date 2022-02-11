class Solution {
    //https://leetcode.com/problems/permutation-in-string/
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp_s1;
        unordered_map<char,int> mp_s2;
        for(auto &c:s1) mp_s1[c]+=1;
        for(auto &c:s2) mp_s2[c]+=1;
        for(auto& [key, val]:mp_s1) if( mp_s2[key] < val) return false;
        
        return true;
            
    }
};

/* testcase 
"ab"
"eidbaooo"
"ab"
"eidboaoo"
*/