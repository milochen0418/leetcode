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
    //https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
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
};