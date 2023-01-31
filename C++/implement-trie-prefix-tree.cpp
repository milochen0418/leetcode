class Trie {
    //https://leetcode.com/problems/implement-trie-prefix-tree/
public:
    
    struct TNode {
        int match;
        vector<TNode*> children;
        TNode(int _match=false) {
            match = _match;
            children = vector<TNode*>(26,nullptr);
        }
        ~TNode(){
            for(auto &child:children) 
                if(child!=nullptr)
                    delete child;
        }
    }; 
    
    TNode *root;
    Trie() {
        root = new TNode();
    }
    ~Trie() {
        delete root;
    }
    
    void insert(string word) {
        TNode* node = root;
        for(auto &c:word) {
            TNode*&child = node->children[c-'a'];
            node = !child?child=new TNode():child;
        }
        node->match = true;
    }
    
    bool search(string word) {
        TNode *node = root;
        for(auto& c:word) {
            TNode*&child = node->children[c-'a'];
            node=child;
            if(!node) return false;
        }
        return node->match;
    }
    
    bool startsWith(string prefix) {
        TNode *node = root;
        for(auto& c:prefix) {
            TNode*&child = node->children[c-'a'];
            node=child;
            if(node==nullptr) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */