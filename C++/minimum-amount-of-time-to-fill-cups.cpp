class Solution {
    //https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups
    //article https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/discuss/2879655/C%2B%2B-or-best-solution-with-3-lines-or-greedy-or-O(1)-or-explanation
    //FB post https://www.facebook.com/groups/1451299754892511/posts/5912270955462013/
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