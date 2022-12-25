class Solution {
    //https://leetcode.com/problems/count-items-matching-a-rule
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int key_idx=0, ans=0;
        if(ruleKey[0]=='c')key_idx=1;
        if(ruleKey[0]=='n')key_idx=2;
        for(auto item:items) if(item[key_idx] == ruleValue) ans++;
        return ans;
    }
};