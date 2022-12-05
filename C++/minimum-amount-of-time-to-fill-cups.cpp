class Solution {
    //https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups
public:
    /*
    The first strategy is always use the maximum element to reduce another remain element.
    If all element in maximul element have become to zero, then we expect the remained two element are in the most balance level, So it need the M/2+M%2 steps to kill all element.     
    */
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        int M = (amount[0]+amount[1]) - amount[2];
        return M<=0?amount[2]:M/2+M%2+amount[2];
    }
};