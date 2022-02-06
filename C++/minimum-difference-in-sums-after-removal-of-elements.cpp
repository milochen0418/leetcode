class Solution {
    //https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/
public:
    long long minimumDifference(vector<int>& nums) {
        int size = nums.size();
        int n = size/3; 
        int min_val = INT_MAX; 
        for(int k=n; k<2*n;k++) {
            int sum=0;
            priority_queue<int, vector<int>, greater<int>> minQ;
            priority_queue<int, vector<int>> maxQ;
            //left
            for(int i=0; i<k; i++) {
                minQ.push(nums[i]);
            }   
            //right
            for(int i=k; i<3*n;i++) {
                maxQ.push(nums[i]);
            }
            
            for(int i=0;i<n;i++) {
                sum += (minQ.top() - maxQ.top());
                minQ.pop();
                maxQ.pop();
            }
            min_val = min(min_val, sum);
        }
        //return sum;
        return min_val;
            // 0 1 2 3 4 5 6 7 8 
            //[0 0 0 1 1 1 2 2 2 ]
    }
};