class Solution {
    //https://leetcode.com/problems/contains-duplicate-iii/
    //set usage for lower_bound, upper_bound
    //https://stackoverflow.com/questions/41958581/difference-between-upper-bound-and-lower-bound-in-stl/70958136#70958136
    /*
    test-cases
[1,2,3,1]
3
0
[1,0,1,1]
1
2
[1,5,9,1,5,9]
2
3    
[8,7,15,1,6,1,9,15]
1
3
[2147483640,2147483641]
1
100
    */
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        set<long> s;
        for(int i=0;i<n;i++) {
            if(i>k) s.erase(nums[i-k-1]);
            long num = nums[i];
            for(auto iter=s.lower_bound(num-t); iter!=s.upper_bound(num+t);iter++) {
                return true;
            }
            s.insert((long)num);
        }
        return false;
    }
};