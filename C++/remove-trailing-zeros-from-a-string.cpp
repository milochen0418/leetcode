class Solution {
    //https://leetcode.com/contest/remove-trailing-zeros-from-a-string/
public:
    string removeTrailingZeros(string num) {
        string ans;
        int n = num.length();
        int flag = 1;
        for(int i = n-1; i>=0;i--) {
            if(num[i] == '0' && flag == 1) {
                //ans.push_back(num[i]);    
            } else {
                flag = 0;
                ans.push_back(num[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};