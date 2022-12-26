class Solution {
    //https://leetcode.com/problems/largest-subarray-length-k/
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size() ;
        unordered_map<int,vector<int>> mp;
        priority_queue<int> maxQ;
        for(int i=0; i<n; i++) {
            mp[nums[i]].push_back(i);
            maxQ.push(nums[i]);
        }
        while(!maxQ.empty()) {
            int e = maxQ.top();
            maxQ.pop();
            int L = mp[e][0], R = n-1;
            if(R-L+1>=k) {
                for(int i = L; i<L+k;i++) {
                  ans.push_back(nums[i]);
                }
                return ans;
            } 
        }
        return vector<int>();
    }
};