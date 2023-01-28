class Solution {
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
public:
    int maxProfit(vector<int>& prices) {
        //Use a little bit idea of  Robber House to think about this idea
        /*
         0 1 2 3 4 
        [1,2,3,0,2]
        cost(i=0) + sol(i+2=2) <-- no way. because buy first and then sell
        .So the first sell must happen in cost(i=1)
        
        cost(i=1) + sol(i+2=3)
        cost(i=2) + sol(i+2=4)
        */
        
        /*[2,1,2,3,0,2]
        cost(i=1) + sol(i+2=3)
        if(we buy for A[0], that's the worst decision)
        cost(i=2) + sol(i+2=4)
        cost(i=3) + sol(i+2=5)
        
        sol(i+2=5) also mean sell (i=3) before. so that why we have sol(i+2=5)
        So sol(0) is mean we sell in cost(-1)=0. And start to find optimize value for sol(0)
        */
        return 0;
    }
};