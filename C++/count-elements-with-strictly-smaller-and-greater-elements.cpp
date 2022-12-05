class Solution {
    //https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements
public:
    int countElements(vector<int>& nums) {
        unordered_set<int> s;
        for(auto&i:nums)s.insert(i); //O(N)
        if(s.size()<3) return 0;        
        sort(nums.begin(), nums.end()); //O(NlogN)
        int n=nums.size(), L = 0, R=n-1;
        while(nums[0]==nums[L])L++; //O(N)
        while(nums[n-1]==nums[R])R--; //O(N)
        return R-L+1;
    }
};
//Time complexity is O(NlogN)
