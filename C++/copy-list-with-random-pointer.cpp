/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    //https://leetcode.com/problems/copy-list-with-random-pointer
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        for(Node* node = head; node!=nullptr; node=node->next) 
            if(mp[node] == nullptr) mp[node] = new Node(node->val);        
        for(Node* node = head; node!=nullptr; node=node->next) {
            mp[node]->next = mp[node->next];
            mp[node]->random = mp[node->random];
        }
        return mp[head];
    }
};