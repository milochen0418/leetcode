class Solution {
    //https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array
    //article https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/discuss/3009659/C%2B%2B-O(N)
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> maxQ;
        for(auto &i:nums) maxQ.push(i);
        int a = maxQ.top();
        maxQ.pop();
        int b = maxQ.top();
        return (a-1)*(b-1);
    }
};