class Solution {
    //https://leetcode.com/problems/construct-the-rectangle
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans={area,1};
        for(int i = 1;i<=sqrt(area);i++) {
            if(area%i==0) {
                int W = i;
                int L = area/i;
                if(L-W < ans[0]-ans[1])ans = {L,W};
            }
        }
        return ans;
    }
};