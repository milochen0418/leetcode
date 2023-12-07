class Solution {
public:
    int minFlips(string target) {
        //Observation 
        //'0'      -> ans=0
        //'1'      -> ans=1
        //'10'     -> ans=2
        //'101     -> ans=3
        //'1010    -> ans=4
        //'10101'  -> ans=5
        //'101010' -> ans=6
        //'1010101'-> ans=7
        int ans = 0, wait_val = 1;
        for(auto &c:target) {
            if(c-'0'==wait_val) {
                wait_val=(wait_val==0);
                ans++;
            }
        }
        return ans;
        
    }
};