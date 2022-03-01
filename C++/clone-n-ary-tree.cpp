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
    //https://leetcode.com/problems/clone-n-ary-tree
    //article https://leetcode.com/problems/clone-n-ary-tree/discuss/1809846/C%2B%2B-or-DFS-or-complexity-analysis-or-O(N)-for-time-and-space
public:
    Node* cloneTree(Node* root) {
        if(root == nullptr) return root;
        Node* clone_root = new Node(root->val);
        int n = root->children.size();
        clone_root->children = vector<Node*>( n ,nullptr);
        for(int i = 0; i<n; i++) {
            clone_root->children[i] = cloneTree(root->children[i]);
        }
        return clone_root;
    }
};