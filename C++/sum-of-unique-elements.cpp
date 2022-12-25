class Solution {
    //https://leetcode.com/problems/sum-of-unique-elements
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> v = vector<int>(101,0);
        for(auto &i:nums) v[i]++;
        int ans = 0;
        for(int i = 0; i<v.size();i++) 
            if(v[i]==1) ans+=i;
        return ans;
    }
};