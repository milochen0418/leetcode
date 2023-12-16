class Solution {
    //https://leetcode.com/problems/html-entity-parser
    //article https://leetcode.com/problems/html-entity-parser/discuss/4411439/C%2B%2B-One-Pass-O(N)-by-Trie-and-Queue
public:
    typedef struct {
        unordered_map<char, void*> mp;
        string* str;
    } Trie;
    string entityParser(string text) {
        Trie* root = new Trie();
        buildTrie(root, "&quot;", "\"");
        buildTrie(root, "&apos;", "'");
        buildTrie(root, "&amp;", "&");
        buildTrie(root, "&gt;", ">");
        buildTrie(root, "&lt;", "<");
        buildTrie(root, "&frasl;", "/");
        
        string output; 
        int i = 0, n = text.length();
        Trie* node = root;
        queue<char> Q;
        while(i<n) {
            while(i<n && node->mp.find(text[i]) != node->mp.end()) {
                node = (Trie*)node->mp[text[i]];
                Q.push(text[i++]);
            } 
            if(node->str) {//match
                output = output + *(node->str);
                while(!Q.empty())Q.pop();
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
    
    void buildTrie(Trie* root, string buildStr, string leafStr) {
        Trie* node=root;
        for(auto &c:buildStr) {
            if(!node->mp[c])  node->mp[c]=(void*)(new Trie());
            node = (Trie*)node->mp[c];
        }
        node->str = &leafStr;
    }
};