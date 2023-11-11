class Solution {
    //https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), ans=0;;
        for(int k=0;k<n;k++) {
            for(int i = 0; i<n;i++) {
                unordered_set<int> s;
                int end = i+k;  
                if(end<n) {
                    for(int j = i; j<=end;j++) 
                        s.insert(nums[j]);
                    ans+=(s.size() * s.size());                    
                }
            }            
        }
        return ans;
    }
};