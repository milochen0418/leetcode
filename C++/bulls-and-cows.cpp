class Solution {
    //https://leetcode.com/problems/bulls-and-cows
public:
    string getHint(string secret, string guess) {
        int a=0, b=0, n = secret.length();
        unordered_map<char,int> mp;
        unordered_map<char,int> gmp;
        for(int i = 0; i<n;i++) {
            mp[secret[i]]++;
            gmp[guess[i]]++;
            if(secret[i] == guess[i]) a++;
        }
        for(auto &[k,v]:mp) {
            b+=min(mp[k],gmp[k]);
        }
        b-=a;
        return to_string(a) + "A"+to_string(b)+"B";
    }
};