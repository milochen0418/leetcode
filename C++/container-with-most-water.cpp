class Solution {
    //https://leetcode.com/problems/container-with-most-water/
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        for(int i = 0; i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans, min(height[i],height[j])*(j-i));
            }
        }
        return ans;
    }
};