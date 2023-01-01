class Solution {
    //https://leetcode.com/problems/distinct-prime-factors-of-product-of-array
    //https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/discuss/2981444/C%2B%2B-or-hash-set
public:
    
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> ss;
        for(auto &num:nums) {
            int n = num;
            int i = 2;
            while( n > 1 ){
                while( n%i == 0 ){
                    ss.insert(i);
                    n = n/i;
                }
                i = i+1;
            }
        }
        return ss.size();
    }
    
    
};