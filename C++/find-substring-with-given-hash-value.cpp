class Solution {
    //https://leetcode.com/problems/find-substring-with-given-hash-value
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        const char* str = s.c_str();
        const int length = s.length();        
        
        for(int pos=0; pos<length-k ;pos++) {
            
            long sum = 0;
            int pi=1;
            for(int i=k-1;~i;i--) {
                sum = (sum*power)%modulo;
                sum = (sum + val(str[pos+i]))%modulo;
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