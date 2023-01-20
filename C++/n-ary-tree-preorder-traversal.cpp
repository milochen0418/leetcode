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
    //https://leetcode.com/problems/n-ary-tree-preorder-traversal
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        function<void(Node*)> dfs = [&](Node* root){
            if(!root) return;
            ans.push_back(root->val);
            for(auto &child:root->children) dfs(child);
        };   
        dfs(root);
        return ans;        
    }

    vector<int> ans;
    vector<int> preorder_v01(Node* root) {
        ans = vector<int>();
        dfs(root);
        return ans;
    }
    void dfs(Node* parent) {
        if(parent!=nullptr) {
            ans.push_back(parent->val);
            for(auto &child: parent->children) dfs(child);
        }        
    }
};