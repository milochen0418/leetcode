class Solution {
public:
    long long smallestNumber(long long num) {
        bool neg = false;
        if(num==0) return 0;
        if(num<0) {
            neg =true;
            num =num * -1;
        }
        string s = to_string(num);
        int n = s.length();
        if(neg) {
            vector<int> vs(n);
            for(int i=0;i<n;i++) {
                vs[i] = s[i]-'0';
            }
            sort(vs.begin(), vs.end());
            reverse(vs.begin(), vs.end());
            long long ret = 0;
            for(int i =0;i<n;i++) {
                ret = ret*10 + vs[i]; 
            }
            return -1*ret;
        } else {
            vector<int> vs(n);
            for(int i=0;i<n;i++) {
                vs[i] = s[i]-'0';
            }
            
            sort(vs.begin(), vs.end()); //01234
            if(vs[0] != 0) {
                long long ret = 0;
                for(int i =0;i<n;i++) {
                    ret = ret*10 + vs[i]; 
                }
                return ret;
            } else {
                for(int i=0;i<n;i++) {
                    if(vs[i] != 0) {
                        int temp = vs[i];
                        vs[i] = vs[0];
                        vs[0] = temp;
                        break;
                    }
                }
                long long ret = 0;
                for(int i =0;i<n;i++) {
                    ret = ret*10 + vs[i]; 
                }
                return ret;                
            }
            
            return 999;
        }
        
    }
};