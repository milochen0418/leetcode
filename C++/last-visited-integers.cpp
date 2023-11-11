
class Solution {
    //https://leetcode.com/problems/last-visited-integers
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {        
        vector<int> nums, ans;
        int cnt=0;
        for(auto &w:words) {
            if(w[0]!='p')  {
                cnt=0;
                int num = stoi(w);
                nums.push_back(num);                
            } else {
                cnt++;
                if(cnt>nums.size()) 
                    ans.push_back(-1);
                else 
                    ans.push_back(nums[nums.size() - cnt]);
            }
        }
        return ans;
    }
};