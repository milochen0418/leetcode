class Solution {
    //https://leetcode.com/problems/separate-the-digits-in-an-array/
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i = nums.size()-1;i>=0;i--) {
            int n = nums[i];
            while(n>0) {
                ans.push_back(n%10);
                n/=10;
            }            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<int> separateDigits_v01(vector<int>& nums) {
        vector<int> ans;
        for(auto &i:nums) {
            vector<int> v;
            int n = i;
            while(n>0) {
                v.push_back(n%10);
                n/=10;
            }
            for(int i=v.size()-1;i>=0;i--) ans.push_back(v[i]);
        }
        return ans;
    }
};