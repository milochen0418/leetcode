class Solution {
    //https://leetcode.com/problems/largest-subarray-length-k/
    //article https://leetcode.com/problems/largest-subarray-length-k/discuss/2954751/C%2B%2B-or-O(N*Log(N))-solution-and-O(N)-solution
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {//O(N)
        vector<int> ans;
        int n=nums.size(), j = n-k; 
        int maxv = nums[n-k];
        for(int i = n-k; i>=0;i--) {
            if(maxv<nums[i]) {
                maxv = nums[i];
                j = i;
            }
        }
        for(int i=j;i<j+k;i++) ans.push_back(nums[i]);
        return ans;
    }

    vector<int> largestSubarray_v01(vector<int>& nums, int k) {//O(NlogN)
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