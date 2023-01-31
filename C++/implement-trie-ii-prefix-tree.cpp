class Trie {
public:
    struct TNode {
        int match;//be a counter. 0:not any matched insert string 
        int through;// be a counter. 3:mean 3 insert string go through it before.
        vector<TNode*> children;
        TNode(int _match=0, int _through=0) {
            match=_match;
            through=_through;
            children = vector<TNode*>(26,nullptr);
        }
        ~TNode() {
            for(auto &child:children)
                if(child!=nullptr) 
                    delete child;
        }
    };
    TNode* root;
    Trie() {
        root = new TNode();            
    }
    ~Trie() {
        delete root;
    }
    
    void insert(string word) {
        TNode* node = root;
        for(auto &c:word) {
            node->through++;
            TNode*&child = node->children[c-'a'];
            node = !child?child=new TNode():child;
        }
        node->match++;
        node->through++;
    }
    
    int countWordsEqualTo(string word) {
        TNode *node = root;
        for(auto &c:word) {
            TNode*& child=node->children[c-'a'];
            if(!child) return 0;
            node=child;
        }
        return node->match;
    }
    
    int countWordsStartingWith(string prefix) {
        TNode *node=root;
        for(auto &c:prefix) {
            TNode*&child = node->children[c-'a'];
            if(!child) return 0;
            node = child;
        }
        return node->through;
        
    }
    
    void erase(string word) {
        TNode* node = root;
        for(auto& c:word) {
            node->through--;
            TNode*& child = node->children[c-'a'];
            node=child;
        }
        node->match--;
        node->through--;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */