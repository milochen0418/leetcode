class Solution {
    //https://leetcode.com/problems/crawler-log-folder
    //article https://leetcode.com/problems/crawler-log-folder/discuss/2996057/C%2B%2B-One-Pass-3-lines
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        for(auto &s:logs) 
            if( 0 > (ans+=(s[0]!='.')-(s[1]=='.')) ) ans=0;
        return ans;
    }
    int minOperations_v01(vector<string>& logs) {
        int ans=0;
        for(auto &s:logs) {
            if(s[0]!='.') 
                ans++;
            else if(s[1]=='.')
                ans--;
            if(ans<0) ans = 0;
        }
        return ans;
    }

};