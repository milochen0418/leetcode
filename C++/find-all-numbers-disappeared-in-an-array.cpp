

class Solution {
    //https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array
    //Refer the usage of unordered_set -> 
    //https://shengyu7697.github.io/std-unordered_set/
    //https://www.geeksforgeeks.org/unordered_set-in-cpp-stl/?ref=lbp
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> uset; 
        for(int num: nums) {
            uset.insert(num);
        }
        
        vector<int> v;
        for(int i = 1; i <= nums.size(); i++) {
            if(uset.find(i) == uset.end()) {
                v.push_back(i);
            }
        }
        return v;
    }
};
