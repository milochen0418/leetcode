class Solution {
    // https://leetcode.com/problems/validate-stack-sequences
    // article https://leetcode.com/problems/validate-stack-sequences/discuss/1853719/C%2B%2B-or-simulate-approach-or-O(n)-or-explain-from-idea-to-source-code.
    // FB post https://www.facebook.com/groups/1451299754892511/posts/5156519707703812/
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        //stack<int> stk;
        int stk_idx=-1;
        int n = pushed.size();
        int pu = 0; //index of pushed vector
        int po = 0; //index of popped vector
        
        while(po<n) { 
            //if(!stk.empty() && stk.top()==popped[po] ) {
            if(stk_idx>=0 && pushed[stk_idx]==popped[po] ) {
                //stk.pop();
                --stk_idx;
                po++;                
            } else {
                if(pu>=n) return false;
                //stk.push(pushed[pu++]);
                pushed[++stk_idx] = pushed[pu++];
            }
        }
        return true;                
    }
};