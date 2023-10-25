class Solution {
    //https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target
public:
    int numOfPairs(vector<string>& nums, string target) {
        int ans=0, n=nums.size(), m = target.length();;
        for(int i = 0; i<n; i++) {
            for(int j = 0 ; j<n;j++) {
                if(j==i) continue;
                string& a = nums[i];
                int am = a.length();
                string& b = nums[j];
                int bm = b.length();
                if(am+bm != m) continue;
                int the_same = 1;
                for(int k =0; k<m && the_same==1; k++ ) {
                    if(k>=am) {
                        if(b[k-am] != target[k]) the_same = 0;
                    } else {
                        if(a[k] != target[k]) the_same = 0;
                    }
                }
                ans+=the_same;
            }
        }
        return ans;
        
    }
};