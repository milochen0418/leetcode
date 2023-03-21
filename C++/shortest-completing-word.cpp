class Solution {
    //https://leetcode.com/problems/shortest-completing-word
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) { 
        vector<int> mp = vector<int>(26,0);
        for(auto &c: licensePlate) {
            if('a'<=c && c<='z') mp[c-'a']++;
            else if('A'<=c && c <='Z') mp[c-'A']++;
        }
        int minlen = INT_MAX;
        string ans = "";
        for(auto &w:words) {
            vector<int> v=mp;
            for(auto &c:w) v[c-'a']--;
            int flag=0;
            for(auto &i:v) if(i>0) {
                flag = 1;
                break;
            }
            if(flag == 0) {
                if(minlen>(int)w.length()) {
                    minlen = (int)w.length();
                    ans = w;
                }
            }
        }
        return ans;
    }
};