class Solution {
    //https://leetcode.com/problems/minimum-deletions-to-make-array-divisible
    //article https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/discuss/2910327/C%2B%2B-or-simple-6-lines-or-N*log(N)
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5949240931765015/
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcdv = 0;
        for(auto& i:numsDivide) gcdv = gcd(i,gcdv);
        sort(nums.begin(), nums.end());
        for(int i =0;i<nums.size() && nums[i]<=gcdv;i++) 
            if(gcdv%nums[i]==0) return i;
        return -1;
    }
};