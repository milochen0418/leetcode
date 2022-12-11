class Solution {
    //https://leetcode.com/problems/longest-square-streak-in-an-array/
public:
    //2^17 > 10^5
    //2^2=4 = 2^2
    //4^2 =16 = 2^4 
    //16^2 = 256 = 2^8
    //256^2 = 65536 = 2^26 
    //最大的答案多就5而己
    typedef long long ll;
    int longestSquareStreak(vector<int>& nums) {
        typedef long long ll;
        unordered_set<ll> s;
        int ans = 0, n = nums.size();
        for(auto &i: nums) s.insert(i);
        for(int i = 0; i<n;i++) {
            ll val =nums[i];
            int q = 1;
            while(s.find(val*val) != s.end()) {
                q=q+1;
                val= val*val;
            }
            ans = max(ans, q);
        }
        if(ans<2) return -1;
        return ans;
    }
    
};