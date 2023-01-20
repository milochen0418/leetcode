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
    //https://leetcode.com/problems/n-ary-tree-postorder-traversal
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        function<void(Node*)> dfs = [&](Node* root){
            if(!root) return;
            for(auto &child:root->children) dfs(child);
            ans.push_back(root->val);
        };   
        dfs(root);
        return ans;
    }
};