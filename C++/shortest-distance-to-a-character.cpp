class Solution {
    //https://leetcode.com/problems/shortest-distance-to-a-character
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length(), idx;
        vector<int> ans = vector<int>(n,n);
        for(int i=0, idx=2*n; i<n; i++) 
            if(s[i]==c) 
                ans[idx=i]=0;
            else 
                ans[i]= min(ans[i],abs(idx-i));
               
        for(int i=n-1, idx=2*n; i>=0; i--) 
            if(s[i]==c) 
                ans[idx = i]=0;
            else 
                ans[i]= min(ans[i],abs(idx-i));
        
        return ans;       
    }
};