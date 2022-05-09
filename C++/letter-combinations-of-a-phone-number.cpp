class Solution {
    //https://leetcode.com/problems/letter-combinations-of-a-phone-number
    //Article https://leetcode.com/problems/letter-combinations-of-a-phone-number/discuss/2021142/C%2B%2B-or-simulated-counting-approach-or
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans = vector<string>();
        if(digits == "") return ans;
        unordered_map<char,string> mp = { 
            {'2',"abc"}, {'3',"def"},{'4', "ghi"},
            {'5',"jkl"}, {'6',"mno"},{'7', "pqrs"},
            {'8', "tuv"},{'9',"wxyz"} 
        };
        
        vector<string> base;
        vector<int>sizev;
        vector<int>idx;
        
        for(int i = 0; i<digits.size(); i++) {
            char c = digits[i];
            base.push_back(mp[c]);
            sizev.push_back(mp[c].size());
            idx.push_back(0);
        }
        
        while(true) {
            string s = string(digits.size(),'\0');
            for(int i = 0; i < digits.size();i++) {
                s[i] = base[i][idx[i]];
            }
            ans.push_back(s);
            if(count_up(idx, sizev)) break;
            //exit loop when counting up to ending.
        }
        return ans;
    }
    
    bool count_up(vector<int>& idx, vector<int>& sizev) { 
        for(int i = idx.size()-1; i>=0 ; i--) {
            idx[i] = idx[i] + 1;
            if(idx[i] < sizev[i]) {
                break;
            } else {
                idx[i] = 0;
                if(i==0) return true; 
                //arrive end of counting up
            }
        }
        return false;
    }
};