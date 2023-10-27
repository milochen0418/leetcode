class Solution {
    //https://leetcode.com/problems/number-of-substrings-with-only-1s
public:
    int numSub(string s) {
        typedef long long ll;
        ll mod = 1e9+7;
        //vector<int> T = {1,3,6,10,15,21,28,36};
        //Observation
        //"1" -> 1        
        //"11" -> 3       
        //"111" -> 6      
        //"1111" -> 10    
        //"11111" -> 15   
        //"111111" -> 21  
        //"1111111" -> 28  
        //"11111111"-> 36   
        //Conclusion: the gap of each two number is 1,2,3,4,5,6...
        
        vector<ll> T = {1};
        s.push_back('0');
        ll cnt = 0, ans=0;
        for(auto &c:s) {
            if(c=='1') {
                cnt++;
                if(cnt>=T.size()) {
                    //T.push_back(T.back()+cnt+1);
                    ll val = T.back()+cnt+1;
                    val %= mod;
                    T.push_back(val);
                }
            } else {//c=='0'
                if(cnt>=1) {
                    //ans += T[cnt-1];
                    ans += T[cnt-1];
                    ans %= mod;
                }
                cnt = 0;
            }
        } 
        return ans;
    }
};