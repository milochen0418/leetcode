class Solution {
    //https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation
    //article https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/discuss/2935287/C%2B%2B-or-design-rotate-lambda-to-solve
public:
    int n;
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<int>>& M=mat, &T = target;
        n = mat.size();
        vector<function<vector<int>(vector<int>)>> Rfs = {
            [&](vector<int>v){ return vector<int>({n-1-v[1],v[0]});}, //degree 90
            [&](vector<int>v){ return vector<int>({n-1-v[0],n-1-v[1]}); }, //degree 180
            [&](vector<int>v){ return vector<int>({v[1],n-1-v[0]}); }, //degree 270
            [&](vector<int>v){ return vector<int>({v[0],v[1]}); } //degree 360
        };
        
        int n2 = n*n;
        for(auto& Rf: Rfs) {
            bool is_break=false;
            for(int k = 0;k<n2;k++) {
                int x=k%n, y=k/n;
                vector<int> t = Rf({x,y});
                if(M[t[0]][t[1]] != T[x][y]) {
                    is_break=true;
                    break;
                }
            }
            if(is_break==false) return true;
        }
        return false;
    }

    bool findRotation_v01(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<int>>& M=mat, &T = target;
        n = mat.size();
        vector<function<vector<int>(vector<int>)>> Rfs = {
            [&](vector<int>v){ return R({v[0],v[1]}); }, 
            [&](vector<int>v){ return R(R({v[0],v[1]})); }, 
            [&](vector<int>v){ return R(R(R({v[0],v[1]}))); }, 
            [&](vector<int>v){ return R(R(R(R({v[0],v[1]})))); }
        };
        
        int n2 = n*n;
        for(auto& Rf: Rfs) {
            bool is_break=false;
            for(int k = 0;k<n2;k++) {
                int x=k%n, y=k/n;
                vector<int> t = Rf({x,y});
                if(M[t[0]][t[1]] != T[x][y]) {
                    is_break=true;
                    break;
                }
            }
            if(is_break==false) return true;
        }
        return false;
    }
    
    vector<int> R(vector<int> xy) { //find rotate index
        /*
        n=6, xy={2,1}
         0 0 0 0 0 0
         0 0 1 0 0 0
         0 0 0 0 0 0
         0 0 0 0 0 0
         0 0 0 0 0 0
         0 0 0 0 0 0
         
        n=6, xy={4,2} = {5-y', x}
         0 0 0 0 0 0
         0 0 0 0 0 0
         0 0 0 0 1 0
         0 0 0 0 0 0
         0 0 0 0 0 0
         0 0 0 0 0 0
         
        n=6, xy={3,4} = {5-y', x}
         0 0 0 0 0 0
         0 0 0 0 0 0
         0 0 0 0 0 0
         0 0 0 0 0 0
         0 0 0 1 0 0
         0 0 0 0 0 0
         
        n=6, xy={1,3} = {5-y', x}         
         0 0 0 0 0 0
         0 0 0 0 0 0
         0 0 0 0 0 0
         0 1 0 0 0 0
         0 0 0 0 0 0
         0 0 0 0 0 0
        */
        
        int x=xy[0], y=xy[1];
        return {n-1-y,x};
    }
};