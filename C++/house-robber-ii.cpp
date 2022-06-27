class Solution {
    //https://leetcode.com/problems/house-robber-ii
public:
    vector<int> a;
    vector<int> ldp;
    vector<int> rdp;
    int rob(vector<int>& nums) {
        a = nums;
        int n = a.size();
        ldp = vector<int>(n+1,-1);
        rdp = vector<int>(n+1,-1);
        
        /*
        Edge case 
        [3] -> 3
        [2] -> 2
        [3,2] -> 3
        [2,3] -> 3

        Observation
        [1,2,3,1,5,6,7] = [1,2,3,1,5,6,_], [_,2,3,1,5,_,7]=[2,3,1,5]+7
        [1,2,3,1,5,6] = [1,2,3,1,5,_], [_,2,3,1,_,6]=[2,3,1]+6
        [1,2,3,1,5] = [1,2,3,1], [_,2,3,_,5]=[2,3]+5
        [1,2,3,1] = [1,2,3,_], [_,2_,1]=[2]+1
        [1,2,3] = [1,2,_], [_,_,3] 
        [1,2] = [1,_], [_,2]
        [1] = [1]
        
        When a = [1,2,3,1,5,6,7]... 
        [1,2,3,1,5,6,7] =     [1,2,3,1,5,6,_], [_,2,3,1,5,_,7]=[2,3,1,5]+7
                 sol(6) = max (  l_sol(5)    , r_sol(4)+a[6] )
        */
        return sol(a.size()-1);
    }
    int sol(int i) {
        return max(l_sol(i-1), r_sol(i-2) + a[i] );
    }
    int l_sol(int i) {
        if(i<0) return 0;
        if(ldp[i] != -1) return ldp[i];
        ldp[i] = max(a[i] + l_sol(i-2), l_sol(i-1) );
        return ldp[i];
        //return max(a[i] + l_sol(i-2), l_sol(i-1) );
    }
    int r_sol(int i) {
        if(i<1) return 0;
        if(rdp[i] != -1) return rdp[i];
        rdp[i] = max(a[i] + r_sol(i-2), r_sol(i-1) );
        return rdp[i];
        //return max(a[i] + r_sol(i-2), r_sol(i-1) );
    }

};