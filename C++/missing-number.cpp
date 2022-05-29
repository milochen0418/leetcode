class Solution {
    //https://leetcode.com/problems/missing-number/
    //article https://leetcode.com/problems/missing-number/discuss/2082536/C%2B%2B-or-4-approach-or-sum-xor-sort-hashset
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5359955194026928/
public:
    int missingNumber(vector<int>& nums) {
        return missingNumberSum(nums);
    }
    //TC: O(N), SC: O(1)
    int missingNumberSum(vector<int>& nums) {
        int ans = 0,n = nums.size();
        //for(int i = 0; i <= n;i++) ans+=i;
        ans = (n*(n+1))/2; //it's the same as the above code but fast.
        for(auto &i:nums) ans-=i;
        return ans;
    }
    //TC: O(N), SC: O(1)
    int missingNumberXOR(vector<int>& nums) {
        int ans = 0;
        for(int i = 0;i<=nums.size();i++) ans= ans^i;
        for(auto& i:nums) ans = ans^i;
        return ans;        
    }
    //TC: O(NlogN), SC:O(1)
    int missingNumberSort(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(ans = 0; ans<nums.size();ans++) if(ans!=nums[ans]) break;
        return ans;
    }
    //TC: O(N), SC:O(N)
    int missingNumberHashSet(vector<int>& nums) {
        int ans;
        unordered_set<int> s;
        for(auto &i:nums) s.insert(i);
        for(ans = 0; ans<=nums.size();ans++) if(s.find(ans)==s.end())break;
        return ans;
    }
};