class Solution {
    //https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array
public:
    struct comp_num_str{
        bool operator()(const std::string& a, const std::string& b) const {
            if(a.length()==b.length()) {
                return a>b;
            } else {
                return a.length() > b.length();
            }
        }
    };  
    
    string kthLargestNumber(vector<string>& nums, int k) {
        //maintain an k number of Min priority_queue
        //keep pop and push new element when size of queue >=k
        priority_queue<string, vector<string>, comp_num_str> minQ;
        for(auto &s: nums) {
            minQ.push(s);
            if(minQ.size()>k) minQ.pop();
        }
        return minQ.top();
    }
};