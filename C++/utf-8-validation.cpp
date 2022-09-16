class Solution {
    //https://leetcode.com/problems/utf-8-validation
public:
    bool validUtf8(vector<int>& d) {
        for(int i = 0;i<d.size();) {
            if ((d[i] & 0x80) == 0 ) {
                i++;
                continue;
            } 
            int n = 0;
            if( (d[i]&0xC0)==0xC0 && (d[i]&0x20)==0 ) {
                n = 2;
            } else if( (d[i]&0xE0)==0xE0 && (d[i]&0x10)==0 ) {
                n = 3;
            } else if( (d[i]&0xF0)==0xF0 && (d[i]&0x08)==0 ) {
                n = 4;
            } else {
                return false;
            }

            n = n + i;
            i++;
            while(i<n) {
                if(i>=d.size()) return false;
                if( (d[i]&0x80)!=0x80 || (d[i]&0x40)!=0 ) return false;
                i++;
            }
        }
        return true;
    }
};