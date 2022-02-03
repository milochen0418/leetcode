class Solution {
    //https://leetcode.com/problems/find-substring-with-given-hash-value
    //Modulo Math : https://en.wikipedia.org/wiki/Modulo_operation
    //Math https://jamboard.google.com/d/1Vx8Tqk-Aph_FftKULHNIsJxdeQCciE5OHTStAwuoiEg/edit?usp=sharing
    
    
/*
test case passed
"xmmhdakfursinye"
96
45
15
21


*/
    
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        const int s_len = s.length();
        
        power = power % modulo;
        vector<int> p(k,1);
        for(int i=1;i<k;i++) { 
            p[i] = ( p[i-1] * power ) % modulo;
        }
        
        vector<int> vs(s_len);
        for(int i=0;i<s_len;i++) {
            vs[i] = (s[i]-'a'+1) % modulo;
        }
                
        for(int idx = 0; idx < s_len-k+1; idx++) {
            int H = 0;
            for(int i=0; i<k; i++) {
                int pos = i + idx;
                int item = (vs[pos]*p[i]) % modulo;
                H = (H + item) % modulo;
            }
            
            if ( H == hashValue ) {
                return s.substr(idx,k);
            }
        }
        return "unknown";
    }
};