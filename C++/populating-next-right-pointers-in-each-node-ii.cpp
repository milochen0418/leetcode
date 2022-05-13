/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    //https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        vector<queue<Node*>> qs = vector<queue<Node*>>(2,queue<Node*>());
        int idx = 0;
        qs[idx].push(root);
        root->next = nullptr;
        
        while(!qs[idx].empty()) {
            Node* e = qs[idx].front();
            qs[idx].pop();
            e->next = qs[idx].empty()?nullptr:qs[idx].front();
            if(e->left != nullptr) qs[(idx+1)%2].push(e->left);
            if(e->right != nullptr) qs[(idx+1)%2].push(e->right);
            if(qs[idx].empty()) idx = (idx+1)%2;
        }
        return root;
    }
};