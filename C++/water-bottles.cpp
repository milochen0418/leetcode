class Solution {
    //https://leetcode.com/problems/water-bottles/
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        while(numBottles>=numExchange) {
            ans+= (numBottles - numBottles%numExchange);
            numBottles = numBottles%numExchange + numBottles/numExchange;
        }
        ans+=numBottles;
        return ans;
    }
};