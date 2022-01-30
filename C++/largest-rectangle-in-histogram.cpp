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
        vector<int> W_R(n), W_L(n), A(n);
        figure(heights, W_R, false);
        figure(heights, W_L, true);
        for(int i=0;i<n;i++) {
            A[i] = heights[i] * (W_R[i] + W_L[i] - 1);
        }
        int max = *max_element(A.begin(), A.end());
        return max;
    }
    
    void figure(vector<int>& H,  vector<int>& W, bool reversed) {
        int n = H.size();
        stack<int>s;
        if(reversed) reverse(H.begin(), H.end());
        for(int i = n-1; i>=0; i--) {
			//keep pop until s is empty or the value 
			//indexed by stack's top less than A[i]
            while(!(s.empty() || H[s.top()]<H[i])) s.pop();
            W[i] = s.empty() ? n-i : s.top()-i;
            s.push(i);
        }
        if(reversed) {
            reverse(H.begin(), H.end());
            reverse(W.begin(), W.end());
        }        
    }

};