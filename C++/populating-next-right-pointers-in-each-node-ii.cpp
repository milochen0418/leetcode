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
    //Article https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/discuss/2036344/C%2B%2B-or-BFS-by-link-list-with-constant-space-or-explanation
    //FB Post https://www.facebook.com/groups/1451299754892511/posts/5315264225162692/
public:
    Node* connect(Node* root) {
        Node* head = root;
        Node* next_head = nullptr, *next_tail = nullptr;
        while(head != nullptr) {
            vector<Node*> childs = {head->left, head->right};
            for(Node* c: childs) {
                if(c == nullptr) continue;
                if(next_head == nullptr) {
                    next_tail = next_head = c;
                } else {
                    next_tail->next = c;
                    next_tail = next_tail->next;
                }
            }
            head = head->next;
            if(head == nullptr) swap(head, next_head);
        }
        return root;
    }

    Node* connectByQueue(Node* root) {
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