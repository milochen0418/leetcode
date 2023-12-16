class Solution {
    //https://leetcode.com/problems/html-entity-parser
public:
    typedef struct {
        unordered_map<char, void*> mp;
        string* str;
    } Tree;
    string entityParser(string text) {
        Tree* root = new Tree();
        buildTree(root, "&quot;", "\"");
        buildTree(root, "&apos;", "'");
        buildTree(root, "&amp;", "&");
        buildTree(root, "&gt;", ">");
        buildTree(root, "&lt;", "<");
        buildTree(root, "&frasl;", "/");
        
        string output; 
        int i = 0, n = text.length();
        Tree* node = root;
        queue<char> Q;
        while(i<n) {
            while(i<n && node->mp.find(text[i]) != node->mp.end()) {
                node = (Tree*)node->mp[text[i]];
                Q.push(text[i++]);
            } 
            if(node->str) {//match
                for(auto &ch:*node->str) output.push_back(ch); 
                while(!Q.empty()) Q.pop(); //clean queue
                node = root;                
            } else { //!node->str
                if(i<n && text[i]!='&') Q.push(text[i++]);
                while(!Q.empty()) {
                    output.push_back(Q.front());
                    Q.pop();
                }
                node = root;
            }
        }        
        return output;
    }
    
    void buildTree(Tree* root, string buildStr, string leafStr) {
        Tree* node=root;
        for(auto &c:buildStr) {
            if(!node->mp[c])  node->mp[c]=(void*)(new Tree());
            node = (Tree*)node->mp[c];
        }
        node->str = &leafStr;
    }
};