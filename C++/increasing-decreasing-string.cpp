class Solution {
    //https://leetcode.com/problems/increasing-decreasing-string
    //article https://leetcode.com/problems/increasing-decreasing-string/discuss/3027455/C%2B%2B-counting-approach-O(N)
public:
    string sortString(string s) {
        string ans;
        vector<int> mp = vector<int>(256,0);
        int maxv = 0;
        for(auto &c: s) maxv = max(maxv, ++mp[c]);
        for(int i = 1;i<= maxv; i++) 
            if(i%2==1) {
                for(char c = 'a'; c<='z';c++) 
                    if(mp[c]>=i) ans.push_back(c);  
            }
            else{
                for(char c = 'z'; c>='a';c--) 
                    if(mp[c]>=i) ans.push_back(c);
            }
        return ans;
    }
};