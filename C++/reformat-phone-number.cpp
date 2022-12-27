class Solution {
    //https://leetcode.com/problems/reformat-phone-number/
public:
    string reformatNumber(string number) {
        string s, ans;
        for(auto &c:number) if('0'<=c&&c<='9') s.push_back(c);
        int n = s.length(); 

        for(auto &c: s) {
            ans.push_back(c); 
            if(detect_4pattern(ans)) {
                //4pattern is like "?1234"
                //so, we want "?12-34"
                //What we do here is converting ?abcd -> ?ab-cd
                process_4pattern(ans);
            } else if (detect_5pattern(ans)) {
                //5pattern is like "?12-345"
                //so, we want "?123-45"
                //What we do here is converting ?ab-cde -> ?abc-de
                process_5pattern(ans);
            }        
        }
        return ans;
        
    }
    void process_4pattern(string &ans) {
        //converting ?abcd -> ?ab-cd
        char d = ans.back(); ans.pop_back();
        char c = ans.back(); ans.pop_back();
        ans.push_back('-'); //pop back '-'
        ans.push_back(c);
        ans.push_back(d);
    }
    void process_5pattern(string &ans) {
        //converting ?ab-cde -> ?abc-de
        char e = ans.back(); ans.pop_back();
        char d = ans.back(); ans.pop_back();
        char c = ans.back(); ans.pop_back();
        ans.pop_back(); //pop back '-'
        ans.push_back(c);
        ans.push_back('-');
        ans.push_back(d);
        ans.push_back(e);
    }
    
    bool is_digit(int idx, string &s) {
        if(idx<0) return false;
        return '0'<=s[idx] && s[idx]<='9';
    }
    bool detect_4pattern(string& s) {
        //The function detect "?1234"
        int n = s.length();
        if(n<4) return false;
        return 
            is_digit(n-1,s) &&
            is_digit(n-2,s) &&
            is_digit(n-3,s) &&
            is_digit(n-4,s) &&
            !is_digit(n-5,s);
    }
    bool detect_5pattern(string& s) {
        //The functon detect "?12-345"
        int n = s.length();
        if(n<6) return false;
        return 
            is_digit(n-1,s) &&
            is_digit(n-2,s) &&
            is_digit(n-3,s) &&
            !is_digit(n-4,s) &&
            is_digit(n-5,s) &&
            is_digit(n-6,s) &&
            !is_digit(n-7,s);
    }
    
};

/*
 2 "12" 
 3 "123"
 4 "12-34" 
 5 "123-45" 
 6 "123-456"
 7 "123-45-67"
 8 "123-456-78" 
 9 "123-456-789"
10 "123-456-78-90"
11 "123-456-789-01"
12 "123-456-789-012"
13 "123-456-789-01-23"
14 "123-456-789-012-34"

  
