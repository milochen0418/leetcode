/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    //https://leetcode.com/problems/maximum-depth-of-n-ary-tree
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int val=0;
        for(auto&c:root->children) val=max(val, maxDepth(c));
        return 1+val;
    }
    
};