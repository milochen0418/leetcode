
class Bitset {
    //https://leetcode.com/problems/design-bitsetgit
public:
    vector<string> v;
    int onecnt = 0;
    int m_flip = 0;
    int m_size = 0;
    Bitset(int size) {
        m_size = size;
        v=vector<string>(2);
        v[0]=string(m_size, '0');
        v[1]=string(m_size, '1');
        onecnt=0;
    }
    
    void fix(int idx) {
        if(idx<0 || idx>=m_size) return;
        if(v[m_flip][idx]=='0') {
            v[m_flip][idx] = '1';
            v[(m_flip+1)%2][idx] = '0';
            onecnt++;
        }
    }
    
    void unfix(int idx) {
        if(idx<0 || idx>=m_size) return;
        if(v[m_flip][idx]=='1') {
            v[m_flip][idx] = '0';
            v[(m_flip+1)%2][idx] = '1';
            onecnt--;
        }        
    }
    
    void flip() {
        m_flip = (m_flip+1)%2;
        onecnt = m_size - onecnt;
    }
    
    bool all() {
        return onecnt==m_size;
    }
    
    bool one() {
        return onecnt>0;
    }
    
    int count() {
        return onecnt; 
    }
    
    string toString() {
        return v[m_flip];
    }
};
