class Trie {
    //https://leetcode.com/problems/implement-trie-ii-prefix-tree
public:
    struct TNode {
        int match;//be a counter. 0:not any matched insert string 
        int through;// be a counter. 3:mean 3 insert string go through it before.
        char c;
        TNode* parent;
        vector<TNode*> children;
        TNode(TNode* _parent=nullptr, char _c='*',int _through=0,int _match=0 ) {
            //Just create TNode's root by call TNode() without any parameter
            parent=_parent;
            c=_c;
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
        root = new TNode();//set through to avoid erase() procedure to erase
    }
    ~Trie() {
        delete root;
    }
    
    void insert(string word) {
        TNode* node = root;
        for(auto &c:word) {
            node->through++;
            TNode*&child = node->children[c-'a'];
            node = !child?child=new TNode(node,c):child;
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
        vector<TNode*> stk;
        
        for(auto& c:word) {
            node->through--;
            if(node->through==0) stk.push_back(node);
            TNode*& child = node->children[c-'a'];
            node=child;
        }
        node->match--;
        node->through--;
        if(node->through==0) stk.push_back(node);
        
        for(int i=stk.size()-1; i>=0;i--) {
            char c = stk[i]->c;
            TNode*parent = stk[i]->parent;
            if(parent) {//parent==nullptr iff current node is root
                parent->children[c-'a']=nullptr;
                delete stk[i];
            }
        }
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