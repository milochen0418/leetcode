class Trie {
    //https://leetcode.com/problems/implement-trie-prefix-tree
public:
    Trie() {
        
    }
    
    void insert(string word) {
        //build the Trie dictionary structure by insert word
        T_insert(root, word);
    }
    
    bool search(string word) {
        //Not only check the path is exist in Trie but also
        //the path need stop at the TNode which have match=true
        TNode *node = T_find(root, word);
        if(!node)return false;
        return node->match;
    }
    
    bool startsWith(string prefix) {
        //Only check the path is exist in Trie by prefix 
        TNode *node = T_find(root, prefix);
        if(!node) return false;
        return true;
    }
private:
    
    struct TNode { //TNode mean Trie Node
        int match;
        vector<TNode*> children;
        TNode(int _match=false) {
            match = _match;
            children = vector<TNode*>(26,nullptr);
        }
        ~TNode() {
            for(auto &child:children) 
                if(child) delete child;
        }
    };
    TNode* root= new TNode();
    
    
    void T_insert(TNode* root, string& s) {
        TNode* node = root;
        for(auto &c:s) {
            if(!node->children[c-'a']) 
                node->children[c-'a'] = new TNode();
            node = node->children[c-'a'];
        }
        node->match = true;
    }
    
    TNode* T_find(TNode* root, string& s) {
        TNode* node = root;
        for(auto& c:s) {
            if(node->children[c-'a'] == nullptr)
                return nullptr;
            node = node->children[c-'a'];
        }
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */