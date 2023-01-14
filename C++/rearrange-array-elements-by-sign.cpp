class Solution {
    //https://leetcode.com/problems/rearrange-array-elements-by-sign
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        vector<int> ans;
        for(auto &i:nums) ((i>0)?pos:neg).push_back(i);
        for(int i = 0;i<nums.size()/2;i++) {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
        
    }
};