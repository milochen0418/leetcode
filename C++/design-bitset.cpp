
class Bitset {
    //https://leetcode.com/problems/design-bitsetgit
public:
    vector<string> v; 
    vector<int> onecnt;
    int m_flip = 0;
    int m_size = 0;
    Bitset(int size) {
        m_size = size;
        v.push_back(string(m_size, '0'));
        onecnt.push_back(0);
        v.push_back(string(m_size, '1'));
        onecnt.push_back(m_size);
    }
    
    void fix(int idx) {
        if(idx<0 || idx>=m_size) return;
        if(v[m_flip][idx]=='0') {
            v[m_flip][idx] = '1';
            onecnt[m_flip]++;
            v[(m_flip+1)%2][idx] = '0';
            onecnt[(m_flip+1)%2]--;   
        }
    }
    
    void unfix(int idx) {
        if(idx<0 || idx>=m_size) return;
        if(v[m_flip][idx]=='1') {
            v[m_flip][idx] = '0';
            onecnt[m_flip]--;
            v[(m_flip+1)%2][idx] = '1';
            onecnt[(m_flip+1)%2]++;
        }        
    }
    
    void flip() {
        m_flip = (m_flip+1)%2;
        
    }
    
    bool all() {
        return onecnt[m_flip]==m_size;
    }
    
    bool one() {
        return onecnt[m_flip]>0;
    }
    
    int count() {
        return onecnt[m_flip]; 
    }
    
    string toString() {
        return v[m_flip];
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */