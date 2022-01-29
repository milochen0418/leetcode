class Solution {
    //Study data for usage of monotonic stack
    //https://leetcode.com/problems/next-greater-element-i/
    //https://www.geeksforgeeks.org/stack-of-pair-in-c-stl-with-examples/
    //https://haogroot.com/2020/09/01/monotonic-stack-leetcode/
    //https://labuladong.gitbook.io/algo-en/ii.-data-structure/monotonicstack
    
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
        reverse(v_w_to_left.begin(), v_w_to_left.end());
        reverse(nums.begin(), nums.end());
        for(int i=0;i<n;i++) {
            v_w[i] = v_w_to_right[i] + v_w_to_left[i] - 1;
            v_area[i] = v_w[i] * nums[i];
        }
        int max = *max_element(v_area.begin(), v_area.end());
        return max;
    }
    
    void figure(vector<int>& nums,  vector<int>& v_w) {
        int n = nums.size();
        vector<int> v(n);
        vector<int> v_idx(n);
        stack<int>s;
        stack<int>s_idx;
        for(int i =  nums.size()-1; i>=0; i--) {
            while(!s.empty() && s.top() >= nums[i]) {
                s.pop();
                s_idx.pop();
            }
            v[i] = s.empty() ? -1: s.top();
            v_idx[i] = s_idx.empty() ? -1: s_idx.top();
            v_w[i] = v_idx[i]!=-1?v_idx[i]-i:n-i;
            s.push(nums[i]);
            s_idx.push(i);
        }
    }  


    vector<int> test_width_figure(){
        vector<int> nums = {2,1,5,6,2,3};  
            // will return [1,5,2,1,2,1]  the width from current to right-most 
        int n = nums.size();
        vector<int> v(n);
        vector<int> v_idx(n);
        vector<int> v_w(n);
        stack<int>s;
        stack<int>s_idx;        
        for(int i =  nums.size()-1; i>=0; i--) {
            while(!s.empty() && s.top() >= nums[i]) {
                s.pop();
                s_idx.pop();
            }
            v[i] = s.empty() ? -1: s.top();
            v_idx[i] = s_idx.empty() ? -1: s_idx.top();
            v_w[i] = v_idx[i]!=-1?v_idx[i]-i:n-i;
            s.push(nums[i]);
            s_idx.push(i);
            
        }
        return v_w;        
    }

};