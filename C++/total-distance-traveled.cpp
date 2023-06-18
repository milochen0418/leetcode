class Solution {
    //https://leetcode.com/problems/total-distance-traveled/
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        while(mainTank>0) {
            if(mainTank < 5) {
                ans += mainTank*10;
                mainTank = 0;
                break;
            } else {
                ans += 5*10;
                mainTank -=5;
                if(additionalTank>0) {
                    mainTank+=1;
                    additionalTank-=1;
                }
            }
        }
        return ans;
    }
};