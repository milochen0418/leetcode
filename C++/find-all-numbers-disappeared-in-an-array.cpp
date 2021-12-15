

class Solution {
    //https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array
    //Refer the usage of unordered_set -> 
    //https://shengyu7697.github.io/std-unordered_set/
    //https://www.geeksforgeeks.org/unordered_set-in-cpp-stl/?ref=lbp
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        return findDisappearedNumbersV02(nums);    
    }
    
    //The answser without uset is refer from here
    //https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/discuss/1583652/C%2B%2B-Short-Solution-%2B-Python-One-Liner-Explained-No-Extra-Space
    vector<int> findDisappearedNumbersV02(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) 
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0) res.push_back(i+1);
        
        return res;
        
    }
    
    vector<int> findDisappearedNumbersV01(vector<int>& nums) {
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
