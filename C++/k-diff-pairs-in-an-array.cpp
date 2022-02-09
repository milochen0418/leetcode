class Solution {
    //https://leetcode.com/problems/k-diff-pairs-in-an-array/
public:
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1,T2> &p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;  
        }
    };
    
    int findPairs(vector<int>& nums, int k) {
        unordered_set< pair<int,int>, pair_hash> s;
        int cnt=0;
        int n = nums.size();
        for(int i = 0; i<n ;i++) {
            for(int j=i+1; j<n;j++) {
                if(abs(nums[i] - nums[j])==k) {
                    int big = nums[j]>nums[i]?nums[j]:nums[i];
                    int small = nums[j]>nums[i]?nums[i]:nums[j];
                    if(s.find({big, small}) == s.end()){
                        s.insert({big, small});
                        cnt++;    
                    }
                    
                }
            }
        }
        return cnt;
    }
};


/* test-case
(1,3), (3,5), (5,3) look like 3? no (3,5)&(5,3) should be the same.

[1,1,3,5,5,3]
2
[3,1,4,1,5]
2
[1,2,3,4,5]
1
[1,3,1,5,4]
0
*/