class Solution {
    //https://leetcode.com/problems/counting-bits
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);   
        for(int i=1,j=1,k=1; i<n+1;i++) {
            ans[i] = ans[i-j]+1;
            if(k==ans[i]) j=1<<k++;
        }
        return ans;
    }
    
    vector<int> answer1(int n) {
        vector<int> ans(n+1,0);
        for(int i = 0; i<=n; i++) {
            int cnt=0;
            for(int j = 0; j<17; j++) {
                if ( (i & (1<<j))>0)cnt++;
            }
            ans[i] = cnt;  
        }
        return ans;                
    }

    vector<int> answer2(int n) {
        vector<int> ans(n+1,0);        
        for(int i=1,j=1; i<n+1;i++) {
            if(i==j*2) j=i;
            ans[i] = ans[i-j]+1;
        }
        return ans;
    }

    vector<int> answer3(int n) {
        vector<int> ans(n+1,0);   
        for(int i=1,j=1,k=1; i<n+1;i++) {
            ans[i] = ans[i-j]+1;
            if(k==ans[i]) j=1<<k++;
        }
        return ans;
    }



};
/* testcase 
100000
*/