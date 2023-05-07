class Solution {
    //https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/
    //add post https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/discuss/3495472/C%2B%2B-or-simple-8-lines-DFS-O(N)
public:
    int minIncrements(int n, vector<int>& cost) {
        cost.insert(cost.begin(),0);
        function<vector<int>(int)> sol = [&](int root) {
            if(root>n) return vector<int>(2,0);
            vector<int> L = sol(root*2);
            vector<int> R = sol(root*2+1);
            return vector<int>{max(L[0],R[0])+cost[root], L[1]+R[1]+abs(L[0]-R[0]) };
        };
        vector<int> ret = sol(1);
        return ret[1];
    }
    
};