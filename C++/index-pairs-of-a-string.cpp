class Solution {
    //https://leetcode.com/problems/index-pairs-of-a-string
    //article: https://leetcode.com/problems/index-pairs-of-a-string/discuss/3058631/C%2B%2B-String-find
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> ans;
        for(auto &w:words) {
            //find all substring in string text that equal to w
            int index =-1;
            while ((index = text.find(w, index+1)) != std::string::npos) {
                ans.push_back({index,index+(int)w.length()-1});
            }            
        }
        sort(ans.begin(), ans.end(), [](auto &lhs, auto &rhs) {
            return lhs[0]==rhs[0]?lhs[1]<rhs[1]:lhs[0]<rhs[0];
        });
        return ans;
        
    }
};