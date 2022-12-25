class Solution {
    
    /*
    0123456789AB
    aabaaaacaabc, k=2
    a= 01..89
    b= 2A..2A 
    c= 7B..7B
    
    //bc "bcbc",
    //ab "aabaaaaaab"
    //ac "aaaaaacaac"
    //someone will be clean first , and letter is our solution
    */
public:
    int takeCharacters(string s, int k) {
        if(checkInvalid(s,k)) return -1;
        printf("\n\n") ;
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
        int show = 1;
        if(show) {        
            for(int i = 0;i<n;i++) 
                printf("%d",sv[i]);
            printf("\n");

            for(int i = 0;i<n;i++) 
                printf("%d[%d,%d,%d], ",sv[i], prefix_av[i][0], prefix_av[i][1], prefix_av[i][2]);
            printf("\n");

            //for(int i = 0;i<n;i++) 
            for(int i = n-1;i>=0;i--) 
                printf("%d[%d,%d,%d], ",sv[i], postfix_av[i][0], postfix_av[i][1], postfix_av[i][2]);
            printf("\n");
        }
        
        
        return 0;
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