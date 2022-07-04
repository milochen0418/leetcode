class Solution {
    //https://leetcode.com/problems/plus-one
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        for(int i=n-1;i>=0;i--) {
            digits[i] += carry;
            carry = digits[i]/10;
            digits[i]%=10;
            if(carry ==0) break;
        }
        
        if(carry == 0) return digits;
        vector<int>ans;
        ans.push_back(carry);
        for(auto &i:digits) ans.push_back(i);
        return ans;
    }
};