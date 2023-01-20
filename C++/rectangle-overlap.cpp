class Solution {
    //https://leetcode.com/problems/rectangle-overlap
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        vector<int>& v=rec2, &w=rec1;
        vector<vector<int>> ps = {{v[0],v[1]}, {v[2],v[3]},{v[0],v[3]},{v[2],v[1]}};
        vector<vector<int>> cs = {{w[0],w[1]}, {w[2],w[3]},{w[0],v[3]},{w[2],v[1]}};
        printf("ps = ");
        for(auto &p:ps)
            printf("(%d,%d), ",p[0],p[1]);
        printf("\n");
        for(auto &p:ps) {
            int is_corner_touch = 0;
            for(auto& c:cs) if(c==p) {
                printf("corner touch (%d,%d)\n", c[0], c[1]);
                is_corner_touch =1;
                break;
                //ignore corner intersection. 
            }
            if(is_corner_touch) continue;
            if(w[0]<=p[0] && p[0]<= w[2]) {
                if(w[1]<=p[1] && p[1] <=w[3]) {
                    printf("(%d,%d) in area\n", p[0],p[1]);
                    return true;            
                }
            }
        }
        return false;
    }
};