class Solution {
    //https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array
public:
    int findMaximumXOR(vector<int>& nums) {
        int mymax = 0;
        int n = nums.size();
        int mask = 0;
        for(int k=30; k>=0; k--) {
            mymax += 1<<k;
            mask |= 1<<k;
            unordered_set<int> s;
            for(auto val: nums) {
                s.insert( (val^mymax)&mask);
            } 
            bool match = false;            
            for(auto num: nums) {
                if( s.find(num & mask) != s.end() ) {
                    match = true;
                    break;                    
                }
            }
            if(match == false) {                
                mymax -= 1<<k;
            }
        }
        return mymax;
    }
    int version1(vector<int>& nums){
        int mymax = INT_MIN;
        int n = nums.size();
        if(n==1) return 0;
        for(int i=0;i<n-1;i++) {
            for(int j = i+1; j<n; j++) {
                mymax = max(mymax, nums[i]^nums[j]);
            }
        }
        return mymax;

    }
};