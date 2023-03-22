class Solution {
    //https://leetcode.com/problems/rectangle-overlap/
public:
    bool isRectangleOverlap(vector<int>& P, vector<int>& Q) {
        //I guess
        //two rectangle P,Q overlap iff one point of P in rect Q or one point of Q in rect P
        vector<vector<int>> Pxy = {{P[0],P[1]}, {P[2],P[1]}, {P[0],P[3]}, {P[2],P[3]}};
        vector<vector<int>> Qxy = {{Q[2],Q[3]}, {Q[0],Q[3]}, {Q[2],Q[1]}, {Q[0],Q[1]}};
        for(auto &q:Qxy)
            if( (P[0]<q[0]&&q[0]<P[2]) && (P[1]<q[1]&&q[1]<P[3]) ) return true;
        swap(P,Q);
        swap(Qxy,Pxy);
        for(auto &q:Qxy)
            if( (P[0]<q[0]&&q[0]<P[2]) && (P[1]<q[1]&&q[1]<P[3]) ) return true;
        return false;
        /*
        cannot pass this test-case after submit
        [7,8,13,15]
        [10,8,12,20]
        */
    }
};