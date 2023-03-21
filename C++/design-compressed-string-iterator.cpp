class StringIterator {
    //https://leetcode.com/problems/design-compressed-string-iterator
    //article https://leetcode.com/problems/design-compressed-string-iterator/discuss/3323593/C%2B%2B-or-One-Pass-O(N)
public:
    string s;
    vector<int> v;
    int idx;
    StringIterator(string compressedString) {
        idx = 0;
        int n = compressedString.length();
        for(auto &c: compressedString)
            if('0'<= c && c<='9') {
                v.back() = v.back()*10+(c-'0');
            } else {
                s.push_back(c);
                v.push_back(0);
            }
    }
    
    char next() {
        if(hasNext() == false) return ' ';
        if(v[idx]<=0) idx++;
        v[idx]--;
        return s[idx];
    }
    
    bool hasNext() {
        if(idx==(int)v.size()-1 && v[idx]==0) return false; 
        return true;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */