class Solution {
    //https://leetcode.com/problems/container-with-most-water/
public:
    int maxArea(vector<int>& a) {
        //return answer1(height);
        int ans = 0, n=a.size(), L=0,R=n-1;
        while(L<=R) {
            ans = max(ans, (R-L)*min(a[L],a[R]));
            if(a[L]<=a[R]) {
                L++;
            } else {
                R--;
            }
        }
        return ans;
    }
    
    int answer1(vector<int>& height) {
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