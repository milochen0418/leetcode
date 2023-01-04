class Solution {
    //https://leetcode.com/problems/crawler-log-folder
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        for(auto &s:logs) 
            if( 0 > (ans+=(s[0]!='.')-(s[1]=='.')) ) ans=0;
        return ans;
    }
};