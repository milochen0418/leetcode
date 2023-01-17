class Solution {
    //https://leetcode.com/problems/kth-largest-element-in-an-array
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> minQ;
        for(auto &i:nums) {
            minQ.push(i);
            if(minQ.size()>k) minQ.pop();
        }
        return minQ.top();
    }
};
/*
Time complexity , O(N*logK)
TODO : Quickselect is O(N) average time complexity 
*/