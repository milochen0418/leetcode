class Solution {
    // https://leetcode.com/problems/validate-stack-sequences
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int n = pushed.size();
        int pu = 0; //index of pushed vector
        int po = 0; //index of popped vector
        while(po<n) { 
            if(!stk.empty() && stk.top()==popped[po] ) {
                stk.pop();
                po++;                
            } else {
                if(pu>=n) return false;
                stk.push(pushed[pu++]);                
            }
        }
        return true;                
    }
};