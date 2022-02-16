class Solution {
    //https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/
    //article https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/discuss/1775064/C%2B%2B-or-HashMap-or-Sliding-Window-or-explanation
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int num = 0;
        int n = s.length();
        if(k>n) return num;
        
        unordered_map<char,int> mp;
        int overcnt = 0;
        for(int i=0; i<k;i++) {
            overcnt += mp[s[i]]>0;
            mp[s[i]] +=1;
        }
        num += overcnt==0;
        
        for(int i=1; i<=n-k; i++) {
            mp[s[i-1]] -= 1;
            overcnt -= mp[s[i-1]] > 0;
            overcnt += mp[s[i+k-1]] > 0;
            mp[s[i+k-1]] +=1;
            num += overcnt==0;
        }
        return num;
    }
};

/* testcase
"havefunonleetcode"
5

*/