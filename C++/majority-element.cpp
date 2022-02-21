class Solution {
    // https://leetcode.com/problems/majority-element
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int cnt = 0;
        int max_cnt = 0; 
        int major = -1;
        int val = nums[0];
        
        for(int i = 0; i<n+1; i++) {
            if(i==n || val != nums[i]) {
                if(cnt > max_cnt) {
                    major = val;
                    max_cnt = cnt;
                    if(i!=n){
                        cnt = 0;
                        val = nums[i];
                    }
                }
            }
            cnt++;
        }   
        //return max_cnt;
        return major;
    }
};