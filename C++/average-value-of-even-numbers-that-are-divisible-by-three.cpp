class Solution {
    //https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/
public:
    int averageValue(vector<int>& nums) {
        int evensum = 0;
        int soln = 0;
        for(auto &i:nums)  {
            if(i%2==0) {
                if(i%3==0) {
                    evensum += i;    
                    soln++;
                }
            }
        }
        if(soln ==0 ) return 0;
        int ans = evensum/soln;
        return ans;

    }
};