class Solution {
    //https://leetcode.com/problems/calculate-delayed-arrival-time/
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime)%24;
    }
};