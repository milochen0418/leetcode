class Solution {
    //https://leetcode.com/problems/single-number
    //article https://leetcode.com/problems/single-number/discuss/1775732/c-3-approach-2-set-1-set-0-set-step-by-step-with-explanation
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s1;
        long long sum = 0; 
        for(auto &num: nums) {
            if(s1.find(num) == s1.end()) {
                s1.insert(num);
                sum += num;
            } else {
                sum -= num;
            }
        }
        return sum;
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
    
    int answer2(vector<int>& nums) {
        unordered_set<int> s1;
        long long sum = 0; 
        for(auto &num: nums) {
            if(s1.find(num) == s1.end()) {
                s1.insert(num);
                sum += num;
            } else {
                sum -= num;
            }
        }
        return sum;
    }
    
    int answer3(vector<int>& nums) {
        int val = 0;
        for(auto& num:nums) val^=num;
        return val;
    }
    
    
};