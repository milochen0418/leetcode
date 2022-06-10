class Solution {
    //https://leetcode.com/problems/longest-substring-without-repeating-characters
    //article https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/2133716/C%2B%2B-or-two-pointer-with-hash-map
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), L = 0, R = 0, ans = 1;
        if(n==0) return 0;
        unordered_map<char,int> mp = {{s[0],1}};
        while(L<n && R<n-1) {
            if(mp[s[R+1]])             
                mp[s[L++]]--;
            else 
                mp[s[++R]]++;
            ans = max(ans, R-L+1);
        }
        return ans;
    }


    int lengthOfLongestSubstringComplicated(string s) {
        int n = s.length();
        if(n==0) return 0;
        unordered_map<char,int> mp;
        mp[s[0]]=1;
        int L = 0, R = 0, ans = 1;
        while(L<n && R<n-1) {
            if(mp[s[R+1]] == 0) {
                mp[s[++R]]++;
            } else {
                while(s[L]!=s[R+1]) mp[s[L++]]=0;
                mp[s[L++]]--;
            }
            /*
            printf("a[%d..%d] = ", L,R);
            for(int i = L; i<=R;i++) {
                printf("%c,",s[i]);
            }
            printf("\n");
            */
            ans = max(ans, R-L+1);
        }
        return ans;
    }
};