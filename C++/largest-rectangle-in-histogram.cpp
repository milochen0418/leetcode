class Solution {
    //Study data for usage of monotonic stack
    //https://leetcode.com/problems/next-greater-element-i/
    //https://www.geeksforgeeks.org/stack-of-pair-in-c-stl-with-examples/
    //https://haogroot.com/2020/09/01/monotonic-stack-leetcode/
    //https://labuladong.gitbook.io/algo-en/ii.-data-structure/monotonicstack
    //https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/1727739/C%2B%2B-or-O(N)-or-monotonic-stack
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> v_w_right(n);
        vector<int> v_w_left(n);
        vector<int> v_area(n);
        figure(heights, v_w_right, false);
        figure(heights, v_w_left, true);
        for(int i=0;i<n;i++) {
            v_area[i] = heights[i] * (v_w_right[i] + v_w_left[i] - 1);
        }
        int max = *max_element(v_area.begin(), v_area.end());
        return max;
    }
    
    void figure(vector<int>& nums,  vector<int>& v_w, bool reversed) {
        int n = nums.size();
        stack<int>s;
        if(reversed) reverse(nums.begin(), nums.end());
        for(int i =  nums.size()-1; i>=0; i--) {
			//keep pop until s is empty or the value 
			//indexed by stack's top less than nums[i]]				
            while( !(s.empty()||nums[s.top()]<nums[i]) ){
                s.pop();
            } 
            v_w[i] = s.empty()?n-i:s.top()-i;
            s.push(i);
        }
        if(reversed) {
            reverse(nums.begin(), nums.end());
            reverse(v_w.begin(), v_w.end());
        }        
    }
};