class Solution {
    //https://leetcode.com/problems/divide-array-into-increasing-sequences
    //article https://leetcode.com/problems/divide-array-into-increasing-sequences/discuss/3099001/C%2B%2B-Greedy-O(N)-with-explanation
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int k) {
        //Think about this case [1,2,3,3,3,3,4,5,6] k=3.  3 is the bottle neck here.
        //You need at least 4 sequence here becuase 3 show 4 times.
        //Think this case [3,3,3,3,4,4,4,4,5,5,5,5] k=3, it will pass. 
        //In here, we try to generate 4 number of 3 and make sure maxv=4 for element 3. 
        //And you cannot generate the solution that cannot be pass if there are maxv*k elements.  
        //This is the observation of Greedy here. 
        
        int maxv=0;
        unordered_map<int,int> mp;
        for(auto &i:nums) maxv = max(maxv, ++mp[i]);
        return maxv*k<=nums.size();
    }
};