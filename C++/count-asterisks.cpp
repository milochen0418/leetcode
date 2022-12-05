class Solution {
    //https://leetcode.com/problems/count-asterisks
public:
    int countAsterisks(string s) {
        int pipe_cnt = 0,ans=0,tmp=0;
        for(auto &c:s) (c=='|' ?pipe_cnt:c=='*' && pipe_cnt%2==0?ans:tmp)++;
        return ans;
    }

    int countAsterisks_v01(string s) {
        int pipe_cnt = 0,ans=0;
        for(auto &c:s) 
            if(c=='|') 
                pipe_cnt++;
            else if(c=='*' && pipe_cnt%2==0)
                ans++;
        return ans;
    }
};