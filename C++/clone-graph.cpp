/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    // https://leetcode.com/problems/clone-graph
public:
    unordered_map <Node*, Node*> mp;
    
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        Node *ans;
        
        if(mp.find(node) == mp.end()) {
            ans = new Node(node->val,  vector<Node*>(node->neighbors.size()) );
            mp.insert({node, ans});
        } else {
            ans = mp[node];
            return ans;
        }
        
        for(int i = 0; i< node->neighbors.size(); i++) {
            ans->neighbors[i] = cloneGraph(node->neighbors[i]);            
        }
        return ans;
    }
};