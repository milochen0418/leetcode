class Solution {
    //https://leetcode.com/problems/queens-that-can-attack-the-king
    //article https://leetcode.com/problems/queens-that-can-attack-the-king/discuss/4375108/C%2B%2B-or-O(N%2BQ)-N%3Aboard-width-Q-number-of-queen
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        //printf("\n\n");
        vector<vector<int>> ans;
        unordered_set<int> set;
        for(auto &q: queens) set.insert(q[0]+ q[1]*8);
        vector<vector<int>> dirs={
            {-1,-1},{ 0,-1},{ 1,-1},
            {-1, 0},        { 1, 0},
            {-1, 1},{ 0, 1},{ 1, 1}
        };
        
        for(auto &d:dirs) {
            int v = king[0] + king[1]*8;
            //printf("d={%d,%d}\n",d[0],d[1]);
            while(v>=0 && v<64) {
                //printf("(%d,%d)",v%8,v/8);
                if(set.find(v) != set.end()) {
                    ans.push_back({v%8, v/8});
                    //printf(". ok");
                    break; 
                }
                if( (v%8)+d[0]<0 || (v%8)+d[0]>=8)break;
                v+=(d[0]+d[1]*8);
            }
            //printf("\n");
        }
        return ans;
    }
};