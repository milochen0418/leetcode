class Solution {
    //https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array
public:
    int differenceOfSum(vector<int>& nums) {
        int sum=0;
        int dsum = 0;
        for(auto &i: nums) {
            sum+=i;
            while(i>0){
                dsum+=i%10;
                i/=10;
            }
        }
        return abs(dsum-sum);
    }
};