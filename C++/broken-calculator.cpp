class Solution {
    //https://leetcode.com/problems/broken-calculator/
    //article https://leetcode.com/problems/broken-calculator/discuss/1876846/C%2B%2B-or-how-to-prove-the-O(logN)-solution-will-always-work
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5177816538907462/
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0; 
        while(target >startValue) {
            ans++;
            if (target %2==1){
                target++;
            } else {
                target/=2;
            }
        }
        return ans + startValue - target;
    }
};