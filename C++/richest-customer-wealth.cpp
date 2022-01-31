class Solution {
    //https://leetcode.com/problems/richest-customer-wealth
public:
    int maximumWealth(vector<vector<int>>& A) {
        vector<int> b = *max_element(A.begin(),A.end(), [](auto l,auto r){ 
            return accumulate(l.begin(),l.end(),0) > accumulate(r.begin(),r.end(),0); 
        });
        return accumulate(b.begin(), b.end(),0);
        //return default_solution(A);
    }
    int default_solution(vector<vector<int>>& A) {
        int max_wealth = 0; 
        for(auto& c:A) 
            max_wealth = max(max_wealth, accumulate(c.begin(), c.end(), 0));
        return max_wealth;
    }
};