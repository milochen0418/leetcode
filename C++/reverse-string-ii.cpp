class Solution {
    //https://leetcode.com/problems/reverse-string-ii
public:
    #define printf(...) empty_printf(__VA_ARGS__)
    #define empty_printf(...)    
    string reverseStr(string s, int k) {
        int i = 0,  n = s.length();
        for(i = 0;  i<n; i+=2*k) { 
            int L = i, R=i+k>n?n-1:i+k-1;
            while(L<R) swap(s[L++], s[R--]);                
        }
        return s;
    }

    string reverseStr_v02(string s, int k) {
        int i = 0,  n = s.length();
        for(i = 0;  i<n; i+=2*k) {            
            if(i+k>n) {
                printf("remaind case 1\n");
                //If there are fewer than k characters left
                int L = i, R=n-1;
                while(L<R) swap(s[L++], s[R--]);                
            } else {
                printf("normal case 3, i=%d,k=%d,n=%d\n",i,k,n);
                int L = i, R=i+k-1;
                while(L<R) swap(s[L++], s[R--]);
            }
        }
        return s;
    }

    string reverseStr_v01(string s, int k) {
        int i = 0,  n = s.length();
        for(i = 0;  i<n; i+=2*k) {            
            if(i+2*k>=n) {
                if(i+k>n) {
                    printf("remaind case 1\n");
                    //If there are fewer than k characters left
                    int L = i, R=n-1;
                    while(L<R) swap(s[L++], s[R--]);
                } else {
                    printf("remaind case 2, i=%d,k=%d,n=%d\n",i,k,n);
                    //If there are less than 2k but greater than or equal to k 
                    int L = i, R=i+k-1;
                    while(L<R) swap(s[L++], s[R--]);  
                }
            } else {//i+2*k<n
                //Normal case
                printf("normal case 3, i=%d,k=%d,n=%d\n",i,k,n);
                int L = i, R=i+k-1;
                while(L<R) swap(s[L++], s[R--]);
            }
        }
        return s;
    }
};