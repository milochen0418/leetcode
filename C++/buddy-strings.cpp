class Solution {
    //https://leetcode.com/problems/buddy-strings
public:
    bool buddyStrings(string s, string goal) {
        int n = s.length();
        if(n!=(int)goal.length()) return false;
        if(s==goal) {
            vector<int> mp=vector<int>(26,0);
            for(auto &c:s) if(++mp[c-'a']>=2) return true;
            return false;
        } else {
            int L=0, R=n-1;
            while(s[L]==goal[L])L++;
            while(s[R]==goal[R])R--;
            if(L==R) return false;
            swap(s[L], s[R]);
            return s==goal;
        }
    }

    bool buddyStrings_v01(string s, string goal) {
        int n = s.length();
        if(n!=(int)goal.length()) return false;
        vector<int> mp=vector<int>(26,0);
        if(s==goal) {
            for(auto &c:s) if(++mp[c-'a']>=2) return true;
            return false;
        } else {
            for(auto &c:s) ++mp[c-'a'];
            for(auto &c:goal) --mp[c-'a'];
            if(mp!=vector<int>(26,0)) return false;
            int L=0, R=n-1;
            while(s[L]==goal[L])L++;
            while(s[R]==goal[R])R--;
            if(L==R) return false;
            swap(s[L], s[R]);
            return s==goal;
        }
    }
};