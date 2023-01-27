class Solution {
    //https://leetcode.com/problems/largest-number
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v;
        
        for(auto &i:nums) {
            string str = to_string(i);
            int m =str.length();
            reverse(str.begin(), str.end());
            str.append( string(9-m,'0'));
            //printf("str=%s\n",str.c_str());
            v.push_back({i, stoi(str)});
        }
        
        sort(v.begin(),v.end(), [&](auto &lhs, auto &rhs){
            return lhs[1]>rhs[1];
        });
        string ans;
        for(auto &w:v) {
            printf("w[0]=%d, w[1]=%d\n",w[0],w[1]);
            ans.append(to_string(w[0]));   
        }
        return ans;
        
        
    }
};

/*
Error Case of this code
Input
[34323,3432]
stdout
w[0]=34323, w[1]=323430000
w[0]=3432, w[1]=234300000

Output
"343233432"
Expected
"343234323"
*/