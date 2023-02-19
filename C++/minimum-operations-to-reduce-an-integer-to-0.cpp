class Solution {
    //https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/
    //article https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/discuss/3204179/C%2B%2B-array-approach
public:
    //39 = 32+4+2+1  = 100111
    
    //54 = 32+16+4+2 = 110110
    //110110 -> 111000 -> 1000 000 -> 000000
    /*
    101 -> 110 -> 1000 -> 0000
    101 -> 100 -> 000 
    convert ruke
    01 -> 1
    011-> 100
    0111->1000
     01111 -> 10000
     
    */
    // 01 -> 1
    // 011 -> 2
    
    int minOperations(int nn) {
        //printf("\n nn = %d\n",nn);
        if(nn==0) return 0;
        string s;
        while(nn>0) {
            s.push_back(nn%2+'0');
            nn/=2;
        }
        s.push_back('0');
        int ans = 0; 
        int cnt = 0;
        
        int n = s.length();
        
        for(int i = 0; i<n;i++) {
            //printf("i=%d\nbefore %s, cnt=%d,ans=%d\n",i,s.c_str(),cnt,ans);
            if(s[i]=='1') {
                cnt++;
                if(i+1>=n || s[i+1]=='0') {
                    if(cnt==1) { //01
                        s[i]='0';
                        ans++;
                    } else { //11111 1 --xxxx
                        s[i+1]='1';
                        ans++;
                        cnt=0;
                    }
                }
            } else {
                cnt=0;
            }
            //printf("after  %s, cnt=%d, ans=%d\n",s.c_str(),cnt,ans);
        }
        return ans;
    }
};