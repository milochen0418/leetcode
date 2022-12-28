class Solution {
    //https://leetcode.com/problems/defuse-the-bomb
    //article https://leetcode.com/problems/defuse-the-bomb/discuss/2962790/C%2B%2B-easy-8-lines
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(k<0) reverse(code.begin(), code.end()) ;
        int n = code.size();
        vector<int> ans = vector(n,0);
        for(int i = 0; i<n;i++) 
            for(int j = (i+1)%n,kk=abs(k); kk>0; kk--,j=(j+1)%n) 
                ans[i]+=code[j];
        if(k<0) reverse(ans.begin(), ans.end());
        return ans;
    }
};