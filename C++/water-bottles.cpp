class Solution {
    //https://leetcode.com/problems/water-bottles/
    //article https://leetcode.com/problems/water-bottles/discuss/3002181/C%2B%2B-One-Pass-simulation
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