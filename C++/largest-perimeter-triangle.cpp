class Solution {
    //https://leetcode.com/problems/largest-perimeter-triangle/
public:
    int largestPerimeter(vector<int>& nums) {
        int largest = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++) 
            for(int j =i+1;j<n;j++) 
                for(int k=j+1;k<n;k++) 
                    largest = max(largest, perimeter(nums[i], nums[j], nums[k]));
        return largest;
    }
    int perimeter(int a, int b, int c) {
        if(a+b<=c || a+c<=b || b+c<=a) return 0;
        return a+b+c;
    }
};