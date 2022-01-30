class Solution {
    //https://leetcode.com/problems/find-substring-with-given-hash-value
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        const char* str = s.c_str();
        const int length = s.length();
        vector<long> p(k);
        long p_val=1;
        for(int i=0;i<k;i++) {
            p[i] = p_val ;
            p_val*=power;
            p_val%=modulo;
        }
        
        for(int pos=0; pos<length-k;pos++) {
            long sum = 0;
            
            for(int i=0;i<k;i++) {
                sum += (val(str[pos+i])*p[i]) ;
                sum %= modulo;
            }

            if(sum == hashValue) {            
                return s.substr(pos,k);                
            }
        }
        return s;
    }
    int val(char c ) {
        return c-'a'+1;
    }
};