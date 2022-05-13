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
        int qidx = 0;
        qs[qidx].push(root);
        root->next = nullptr;
        
        while(!qs[qidx].empty()) {
            queue<Node*>& q = qs[qidx];
            queue<Node*>& nextQ = qs[(qidx+1)%2];
            Node* e = q.front();
            cout<<e->val<<" ";
            q.pop();
            e->next = q.empty()?nullptr:q.front();
            if(e->left != nullptr) nextQ.push(e->left);
            if(e->right != nullptr) nextQ.push(e->right);
            if(q.empty()) qidx = (qidx+1)%2;
        }
        return root;
    }
};