class Solution {
    //https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero
    //article https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/discuss/2079926/C%2B%2B-or-Only-lg(N)-times-and-Space-O(1)-or-Explanation
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5357773284245119/
public:
    int numberOfSteps(int num) {
        int ans=0;
        while(num>0) {
            ans += num & 1;
            num = num>>1;
            ans += (num>0);
        }
        return ans;
    }
};