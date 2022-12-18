class Solution {
    //https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors
public:
    int smallestValue(int n) {
        unordered_map<int,int> mp = dig(n);
        int prev_cur = INT_MAX;
        int cur = n;
        
        while(prev_cur > cur) {
            prev_cur = cur;
            mp = dig(cur);
            cur = 0;
            for(auto &[prime,cnt]:mp) {
                cur+=prime*cnt;
            }
        }
        return cur;   
    }
    
    /*
    If n = 3*5*5 = 75 , then dig(75) will get the following map
    mp[3] = 1
    mp[5] = 2
    
    Then we need to figure out sum of all proime 3+5+5 = 3*1+5*2
    We know that mp[prime] = cnt
    So by the map's information, sum = prime1*cnt1 + prime2*cnt2 ....
    */
    unordered_map<int,int> dig(int n ) {
        unordered_map<int,int> mp;
        int i = 2;
        while( n > 1 ){
            while( n%i == 0 ){
                mp[i]++;
                n = n/i;
            }
            i = i+1;
        }
        return mp;
    }
    
     
};