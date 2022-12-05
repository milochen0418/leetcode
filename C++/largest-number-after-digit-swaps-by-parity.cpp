class Solution {
    //https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity
public:
    int largestInteger(int num) {
        string s = to_string(num), s_odd, s_even,ansstr;
        int n = s.length();
        vector<int> idxs_odd, idxs_even;
        for(int i = 0; i < n;i++) {
            (((s[i]-'0')%2==0)?idxs_even:idxs_odd).push_back(i);
            (((s[i]-'0')%2==0)?s_even:s_odd).push_back(s[i]);
        }
        sort(s_even.begin(), s_even.end(), greater<char>());
        sort(s_odd.begin(), s_odd.end(), greater<char>());
        int i=0,j=0,k=0, ans=0;
        for(k = 0;k<n;k++) {
            if(i<idxs_odd.size() && idxs_odd[i]==k) 
                ans = ans*10 + (s_odd[i++]-'0');
            else 
                ans = ans*10 + (s_even[j++]-'0');
        }
        return ans;
    }
};