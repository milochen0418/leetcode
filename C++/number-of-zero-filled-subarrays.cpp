class Solution {
    //https://leetcode.com/problems/number-of-zero-filled-subarrays
    //article https://leetcode.com/problems/number-of-zero-filled-subarrays/discuss/3322271/C%2B%2B-or-One-Pass-O(N)-with-explanation
public:
    typedef long long ll;
    long long zeroFilledSubarray(vector<int>& nums) {
        /*
        Observation 
        0 0 0 contribute 3+2+1
        0 0 contribute 2+1
        0 contriute 1
        k number of zero contribute (k*(k+1))/2
        */
        nums.push_back(1);
        ll k = 0, ans=0; 
        for(auto &i: nums){
            if(i!=0) {
                ans += (k*(k+1))/2;
                k=0;
            } else {
                k++;
            }
        }
        return ans;
    }

    long long zeroFilledSubarray_v01(vector<int>& nums) {
        //refactor but slower version
        nums.push_back(1);
        ll k = 0, ans=0; 
        for(auto &i: nums)
            if(i!=0) 
                k=0;
            else 
                ans+=++k;
        return ans;
    }
};