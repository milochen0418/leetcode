class Solution {
    //https://leetcode.com/problems/sum-of-all-subset-xor-totals
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        /*
        n=1, 0,1 0-1
        n=2, 00,01,10,11  0-3
        n=3, 000,001,010,011,100,101,110,111 <-- all subset can be indicated.
        */
        int sum = 0;
        for(int i = 0; i<(1<<n);i++) {
            int xortotal = 0;
            for(int q=0;q<n;q++) {
                if( ((1<<q) & i) > 0 ){
                   xortotal^=nums[q];
                }
            }       
            sum += xortotal;
        }
        return sum;
    }
};