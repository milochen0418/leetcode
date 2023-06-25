class Solution {
    //https://leetcode.com/problems/number-of-beautiful-pairs/
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            for(int j = i+1;j<n;j++) {
                string str1 = to_string(nums[i]);
                string str2 = to_string(nums[j]);
                int d1 = str1[0]-'0';
                int d2 = str2[((int)str2.length())-1] - '0';
                if(gcd(d1,d2) == 1) ans++;
            }
        }
        return ans;
    }
};