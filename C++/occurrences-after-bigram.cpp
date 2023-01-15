class Solution {
    //https://leetcode.com/problems/occurrences-after-bigram
    //article https://leetcode.com/problems/occurrences-after-bigram/discuss/3053676/C%2B%2B-Two-Pass-O(N)
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> input, ans; 
        
        text.push_back(' ');
        string s;
        for(auto &c:text) {
            if(c!=' ') {
                s.push_back(c);
            } else {
                input.push_back(s);
                s="";
            }
        }
        int n = input.size();
        for(int i = 2; i<n;i++) 
            if(input[i-2] == first && input[i-1]==second) 
                ans.push_back(input[i]);
        return ans;
    }
};