/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    //https://leetcode.com/problems/construct-quad-tree
    //article https://leetcode.com/problems/construct-quad-tree/discuss/3235794/C%2B%2B-recursion-O(grid-size)-16-lines
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size(),xx = 0;
        for(xx = 0;xx<=6;xx++) if((1<<xx) == n) break;
        function<Node*(int,int,int,int,int)> build = [&](int r0, int c0, int r1, int c1,int x) {
            if(x==0) return new Node(grid[r0][c0],true);
            int h = (1<<(x-1));//half width
            Node *tl = build(r0  , c0  , r0+h, c0+h, x-1);
            Node *tr = build(r0  , c1-h, r0+h, c1  , x-1);
            Node *bl = build(r1-h, c0  , r1  , c0+h, x-1);
            Node *br = build(r1-h, c1-h, r1  , c1  , x-1);            
            if(tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf) 
                if(tl->val == tr->val && bl->val == br->val && tl->val == bl->val) 
                    return new Node(tl->val, true);
            return new Node(0,false,tl,tr,bl,br);
        };
        Node * t = build(0,0,n,n, xx);
        return t;
    }
};