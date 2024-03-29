class Solution {
    //https://leetcode.com/problems/maximum-units-on-a-truck
    //article https://leetcode.com/problems/maximum-units-on-a-truck/discuss/2954689/C%2B%2B-or-simulate-approach-with-sorting
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int total = truckSize;
        sort(boxTypes.begin(), boxTypes.end(), [](auto &lhs, auto &rhs){
            return lhs[1]>rhs[1];
        });
        int ans=0;
        for(auto &box: boxTypes) {
            for(int i = 0;i<box[0];i++) {
                ans+=box[1];
                total-=1;
                if(total==0) return ans;
            }
        }
        return ans;
    }
};