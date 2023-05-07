class Solution {
    //https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> A = vector<int>(n,0);
        int m = queries.size();
        vector<int> ans = vector<int>(m,0);
        int prev_ans=0;
        for(int i = 0; i<m;i++) {
            vector<int> &q = queries[i];
            int index = q[0];
            int old_color = A[index];
            int new_color = q[1];
            int cnt = 0;
            if(old_color == new_color ) {
                ans[i] = prev_ans;
                continue;
            }
            
            A[index] = new_color;
            if(index-1>=0 && A[index-1]!=0) {
                if(old_color == A[index-1]) cnt--;
                if(new_color == A[index-1]) cnt++;
            }
            if(index+1<n && A[index+1]!=0) {
                if(old_color == A[index+1]) cnt--;
                if(new_color == A[index+1]) cnt++;
            }
            ans[i] = prev_ans + cnt;
            prev_ans = ans[i];
        }
        return ans;
    }
};