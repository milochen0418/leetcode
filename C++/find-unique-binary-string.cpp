class Solution {
    //https://leetcode.com/problems/find-unique-binary-string
public:
    string findDifferentBinaryString(vector<string>& nums) {
        //n=16, so 2^16 can be preresented by integer 
        unordered_set<int> A;
        for(auto &s: nums) {
            int v = 0; 
            for(auto &c: s) v = v*2 + (c-'0');
            A.insert(v);
        }
        int n = nums.size();
        string ans = string(n,'0');
        n = 1<<n;
        for(int i=0;i<n;i++) {
            if(A.find(i) == A.end()) {
                int m = i;
                int j = 0;
                while(m>0) {
                    ans[j++] += (m%2);
                    m/=2;
                }
                break;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};