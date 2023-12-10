class Solution {
    //https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
    //article https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/discuss/4386999/C%2B%2B-simulate-O(N)
public:
    int numSteps(string s) {
        s = "0"+s; 
        int ans = 0;
        
        while(  //while (s != "01" && s != "1")
            (!(s.length()==1 && s[0]=='1'))  &&
            (!(s.length()==2 && s[0]=='0' && s[1]=='1'))
         ) {
            if(s.back()=='0') {
                s.pop_back();
                ans++;
            } else {
                int n = s.length();
                int i = n-1;
                for(; i>=0; i--) {
                    if(s[i]=='0') {
                        s[i]='1';
                        ans=ans+1;
                        break;
                    } else {
                        s[i]='0';
                    }
                }
            }
        }
        return ans;
    }
};