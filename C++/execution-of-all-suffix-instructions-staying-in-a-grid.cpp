class Solution {
    //https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> pos = startPos, ans;
        int m = s.length();
        for(int i = 0; i<m;i++) {
            pos = startPos;
            int j = i;
            for(; j<m;j++) {
                char ch = s[j];
                int cdiff = -1*(ch=='L') + 1*(ch=='R');
                int rdiff = -1*(ch=='U') + 1*(ch=='D');
                int r = pos[0]+rdiff; 
                int c = pos[1]+cdiff;
                if( (c<0||c>=n)  || (r<0||r>=n)) break;
                pos = {r,c};
            }
            ans.push_back(j-i);
        }
        return ans;
    }
};