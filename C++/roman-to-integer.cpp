class Solution {
    //https://leetcode.com/problems/roman-to-integer
    //article https://leetcode.com/problems/roman-to-integer/discuss/3028914/C%2B%2B-One-Pass-O(N)-8-lines
public:
    int romanToInt(string s) {
        vector<int>mp={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,100,500,0,0,0,0,1,0,0,50,1000,0,0,0,0,0,0,0,0,5,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};        
        int n = s.length(), ans=0;
        s.push_back(0);
        for(int i=0; i<n; i++) {
            if(mp[s[i]] < mp[s[i+1]]) ans+=-1*mp[s[i++]];
            ans+=mp[s[i]];
        }
        return ans;
    }

    int romanToInt_v01(string s) {
        /*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000        
        */
        unordered_map<char,int> mp = {
            {'I',1},{'V',5},{'X',10},{'L',50},
            {'C',100},{'D',500},{'M',1000}
        };
        
        int n = s.length();
        int sum=0;
        for(int i=0; i<n; i++) {
            if(i+1<n && mp[s[i]] < mp[s[i+1]]) {
                sum+=mp[s[i]]*-1;
                sum+=mp[s[i+1]];
                i++;
            } else {
                sum+=mp[s[i]];
            }
        }
        return sum;
    }
};