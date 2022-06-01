class Solution {
    //https://leetcode.com/problems/minimum-knight-moves
public:
    struct RC{
        int row;int col;
        RC(int row, int col):row(row), col(col){}
        RC(int id ):row(id/300), col(id%300) {}
        int getId() {return (row)*300 + col;}
    };
    int minKnightMoves(int x, int y) {
        vector<RC> dirs = {
               RC{-2,-1},  RC{-2,+1},
            RC{-1,-2},       RC{-1,+2},
            RC{+1,-2},       RC{+1,+2},
               RC{+2,-1},  RC{+2,+1}
        };
        
        queue<RC> currQ_real;
        queue<RC> nextQ_real;
        queue<RC> *currQ = &currQ_real;
        queue<RC> *nextQ = &nextQ_real;
        
        unordered_set<int> ss;
        currQ->push(RC{0,0});
        //ss.insert(RC{0,0});
        int ans = 0;
        RC match = RC{x,y};
        while(!currQ->empty()) {
            RC e = currQ->front();
            if(e.row == match.row && e.col == match.col) return ans;
            
            currQ->pop();
            for(auto &dir: dirs) {
                RC newE = RC{e.row+dir.row, e.col+dir.col};
                if(ss.find(newE.getId()) == ss.end()) {
                    ss.insert(newE.getId());
                    nextQ->push(newE);
                }
            }
            
            if(currQ->empty()) {
                queue<RC>* tmp = currQ;
                currQ = nextQ;
                nextQ = tmp;
                ans++;
            }
        }
        return 0;
    }
};