class Solution {
    //https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i
public:
    long long maximumTripletValue(vector<int>& nums) {
        typedef long long ll;
        int n = nums.size();
        ll ans=0;
        for(int i = 0; i<n; i++) 
            for(int j = i+1; j<n; j++)
                for(int k = j+1; k<n; k++)
                    ans = max(ans, ((ll)nums[i]-(ll)nums[j])*(ll)nums[k]);
        return ans;
    }
};