class Solution {
    //https://leetcode.com/problems/hexspeak
public:
    vector<char> digit_to_letter = {
        'O','I','2','3','4','5','6','7',
        '8','9','A','B','C','D','E','F'
    };
    string toHexspeak(string num) {
        string ans;
        long n = stol(num);
        while(n>0) {
            int digit = n%16;
            if(digit>1 && digit<10) return "ERROR";
            ans.push_back(digit_to_letter[digit]);
            n/=16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};