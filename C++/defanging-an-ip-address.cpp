class Solution {
    //https://leetcode.com/problems/defanging-an-ip-address
public:
    string defangIPaddr(string address) {
        string ans;
        for(auto &c:address) 
            if(c!='.') 
                ans.push_back(c);
            else
                ans.append("[.]");
        return ans;
    }
};