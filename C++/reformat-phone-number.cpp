class Solution {
    //https://leetcode.com/problems/reformat-phone-number
public:
    string reformatNumber(string number) {
        string s;
        for(auto &c:number) if('0'<=c&&c<='9') s.push_back(c);
        string ans;
        int n = s.length(); 
        for(int i = 0; i<n; i++) {
            if(i==3)ans.push_back('-');
            if(i>3 && (i-3)%2==0) ans.push_back('-');
            //if(i!=0 && i%3==0) ans.push_back('-');
            ans.push_back(s[i]);
        }
        return ans;
        
    }
};
/*
"12"
"123"
"12-34"
"123-45"
"123-456"
"123-45-67"
"123-456-78"
"123-456-789"
"123-456-78-90"
"123-456-789-01"
"123-456-789-012"
"123-456-789-01-23"
"123-456-789-012-34"
*/