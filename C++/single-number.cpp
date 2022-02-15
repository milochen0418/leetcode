class Solution {
    //https://leetcode.com/problems/single-number
public:
    int singleNumber(vector<int>& nums) {
        //return answer1(nums);
        int val = 0;
        for(auto& num:nums) val^=num;
        return val;
    }
    
    int answer1(vector<int>& nums) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        for(auto &num: nums) {
            if(s1.find(num) == s1.end()) {
                s1.insert(num);
            } else {
                s2.insert(num);
            }
        }
        for(auto &num: nums) {
            if(s2.find(num) == s2.end()) {
                return num;
            }
        }
        return 0;
        
    }
};