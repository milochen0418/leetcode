class Solution {
    //Study data for usage of monotonic stack
    //https://leetcode.com/problems/next-greater-element-i/
    //https://www.geeksforgeeks.org/stack-of-pair-in-c-stl-with-examples/
    //https://haogroot.com/2020/09/01/monotonic-stack-leetcode/
    //https://labuladong.gitbook.io/algo-en/ii.-data-structure/monotonicstack
    
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<pair<int,int>>> s;
        int n = heights.size();
        for(int i = 0; i<n;i++) {
            int h = heights[i];
            if(s.empty() || h < s.top().first) {
                s.push(  s.top().second)
            }
            
        }
        return 1;
    }
};