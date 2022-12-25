class Solution {
    //https://leetcode.com/problems/take-k-of-each-character-from-left-and-right
    
    //|0 1 2 3 4 5 6 7 8 9 A B <-- index
    //[a]a b a a a a c a a b c
    //[a a]b a a a a c a a b c
    //[a a b]a a a a c a a b c
    // a a b[a]a a a c a a b c
    // a a b[a a a a c]a a b c
    // a a b a a a a c[a]a b c
    // a a b a a a a c[a a b]c
    // a a b a a a a c a a b[c]

public:
    int takeCharacters(string s, int k) {
        if(k==0) return 0;
        int n = s.length();
        vector<int> mp=vector<int>(3,0);
        for(int i = 0;i<n;i++) mp[s[i]-='a']++;
        if(mp[0]<k || mp[1]<k || mp[2]<k) return -1;
        int L = 0, R=-1, max_w = 0;
        while(L<n && R<n) {
            if(mp[0]<k || mp[1]<k || mp[2]<k) {
                mp[s[L]]++;
                L=L+1;                
            } else {
                R=R+1;
                mp[s[R]]--;                
            }
            max_w = max(max_w, R-L+1);
        }
        return n-(max_w-1);        
    }

    int takeCharacters_v01(string s, int k) {
        if(k==0) return 0;
        if(checkInvalid(s,k)) return -1;
        //printf("\n\n") ;
        int n = s.length();
        vector<int>sv = vector<int>(n,0); //sv will be 0,1,2 (mapping to abc)
        for(int i = 0; i<n;i++) {
            sv[i] = s[i] - 'a';
        }
         
        
        vector<int>prefix_mp = vector<int>(3,0);
        vector<int>postfix_mp = vector<int>(3,0);
        vector<vector<int>> prefix_av = vector<vector<int>>(n,vector<int>());
        vector<vector<int>> postfix_av = vector<vector<int>>(n,vector<int>());
        
        for(int i =0;i<n;i++) {
            prefix_mp[sv[i]]++;
            prefix_av[i]=prefix_mp;
        }
        
        for(int i=n-1;i>=0;i--) {
            postfix_mp[sv[i]]++;
            postfix_av[i]=postfix_mp;
        }
        
        int show = 0;
        if(show) {        
            for(int i = 0;i<n;i++) 
                printf("%d",sv[i]);
            printf("\n");

            for(int i = 0;i<n;i++) 
                printf("%d[%d,%d,%d], ",sv[i], prefix_av[i][0], prefix_av[i][1], prefix_av[i][2]);
            printf("\n");

            for(int i = 0;i<n;i++) 
            //for(int i = n-1;i>=0;i--) 
                printf("%d[%d,%d,%d], ",sv[i], postfix_av[i][0], postfix_av[i][1], postfix_av[i][2]);
            printf("\n");
        }
        int L=0,R=-1;//(L,R]
        int max_illegal_width = 0;
        vector<int> valZ = {0,0,0};
        while(L<n && R<n) {
            vector<int>& valL = L-1>=0 ?  prefix_av[L-1] : valZ;
            vector<int>& valR = R+1< n ? postfix_av[R+1] : valZ;
            if( legal(valL, valR, k) ) {
                R=R+1;
            } else {
                L=L+1;
            }
            max_illegal_width = max(max_illegal_width, R-L+1);
            //printf("LR = %d,%d ;max_w=%d\n",L,R, R-L+1);
        }
        
        //printf("max_illegal_width = %d\n", max_illegal_width);
        return n-(max_illegal_width-1);
    }
    
    bool legal(vector<int>& valL, vector<int>& valR, int &k) {
        if(valL[0] + valR[0]<k) return false;
        if(valL[1] + valR[1]<k) return false;
        if(valL[2] + valR[2]<k) return false;
        return true;
    }
    bool checkInvalid(string &s, int k) {
        int n = s.length();
        unordered_map<char, vector<int>> mp;
        for(int i = 0; i<n;i++) {
            mp[s[i]].push_back(i);
        }
        if(mp.size()<3) return true;
        for(auto &[c,v]:mp) {
            if(v.size()<k) return true;
        }
        return false;
    }
    
};