class Solution {
    //https://leetcode.com/problems/decompress-run-length-encoded-list
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        n/=2;
        for(int i = 0; i<n;i++) {
            int freq = nums[2*i];
            int val = nums[2*i+1];
            for(int j=0;j<freq;j++) {
                ans.push_back(val);
            }
        }
        return ans;
    }
};