class Solution {
    //Study data for usage of monotonic stack
    //https://leetcode.com/problems/next-greater-element-i/
    //https://www.geeksforgeeks.org/stack-of-pair-in-c-stl-with-examples/
    //https://haogroot.com/2020/09/01/monotonic-stack-leetcode/
    //https://labuladong.gitbook.io/algo-en/ii.-data-structure/monotonicstack
    //https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/1727739/C%2B%2B-or-O(N)-or-monotonic-stack
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>& nums = heights;
        int n = nums.size();
        vector<int> v_w_to_right(n);
        vector<int> v_w_to_left(n);
        vector<int> v_w(n);
        vector<int> v_area(n);
        figure(nums, v_w_to_right);
        reverse(nums.begin(), nums.end()); 
        figure(nums, v_w_to_left); 
		//Use reverse order of heights figure out the result
		//but remember the result is not normal order.
        reverse(v_w_to_left.begin(), v_w_to_left.end()); 
		//reverse the result to get real v_w_toleft 
        reverse(nums.begin(), nums.end());
		//nums become normal order of heights now.
        for(int i=0;i<n;i++) {
            v_w[i] = v_w_to_right[i] + v_w_to_left[i] - 1;
            v_area[i] = v_w[i] * nums[i];
        }
        int max = *max_element(v_area.begin(), v_area.end());
        return max;
    }
    
    void figure(vector<int>& nums,  vector<int>& v_w) {
        int n = nums.size();
        stack<int>s;
        for(int i =  nums.size()-1; i>=0; i--) {
			//keep pop until s is empty or the value 
			//indexed by stack's top less than nums[i]]				
            while( !(s.empty()||nums[s.top()]<nums[i]) ){
                s.pop();
            } 
            v_w[i] = s.empty()?n-i:s.top()-i;
            s.push(i);
        }
    }
};