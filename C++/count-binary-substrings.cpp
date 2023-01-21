class Solution {
    //https://leetcode.com/problems/count-binary-substrings
public:
    // Explanation
    //   "000111001100001111" <-- Input
    //v = -1,2,5,7,9,13,17,
    //      3,2,2,2,4, <-- min(Lcnt,Rcnt)
    //Output =3+2+2+4 = 13
    int countBinarySubstrings(string s) {
        int n = s.length(), ans = 0;
        vector<int> v={-1};
        for(int i = 1; i<n;i++) 
            if(s[i]!=s[i-1]) 
                v.push_back(i-1);
        v.push_back(n-1);
        
        for(int i = 1; i<v.size()-1;i++) {
            int Lcnt = v[i]-v[i-1];
            int Rcnt = v[i+1]-v[i];
            ans+=min(Lcnt, Rcnt);
        }
        return ans;
    }

    int countBinarySubstrings_TLE(string s) {
        int n = s.length(), ans = 0;
        for(int i = 0;i<n-1;i++) {
            char L = s[i];
            int Lcnt = 0, j = i;
            while(j<n && s[j++]==L) Lcnt++;
            j-=1;
            while(j<n && s[j++]!=L) {
                Lcnt--;
                if(Lcnt==0) break;
            }
            if(Lcnt==0) ans++; 
        }
        return ans;
    }
};