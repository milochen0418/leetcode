class Solution {
    //https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/
public:
    int largestInteger(int num) {
        string s = to_string(num);
        int n = s.length();
        vector<int> sv = vector<int>(n,0);
        for(int i = 0; i<n;i++) sv[i] = s[i]-'0';
        
            
        vector<int> odd;
        vector<int> odd_idx;
        vector<int> even;
        vector<int> even_idx;
        for(int i = 0; i<n;i++) {
            int val = sv[i];
            if(val%2==0) {
                even.push_back(val);
                even_idx.push_back(i);
                
            } else {
                odd.push_back(val);
                odd_idx.push_back(i);
            }
        }
        sort(even.begin(), even.end(), greater<int>());
        sort(odd.begin(), odd.end(), greater<int>());
        
        for(int i = 0;i<even.size();i++) {
            sv[even_idx[i]] = even[i];
        }
        for(int i = 0;i<odd.size();i++) {
            sv[odd_idx[i]] = odd[i];
        }
        int ans = 0;
        for(auto &i:sv) {
            ans = (ans*10)+i;
        }
        return ans;
        
        
        return 0;
            
        
    }
};