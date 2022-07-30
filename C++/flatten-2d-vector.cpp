class Vector2D {
    //https://leetcode.com/problems/flatten-2d-vector
public:
    int i=0,j=0;
    bool currHasNext = false;
    vector<vector<int>> a;
    int n = 0;
    int cnt = 0;
    Vector2D(vector<vector<int>>& vec) {
        a = vec;
        for(int i = 0; i< a.size();i++) n+=a[i].size();
        i=0;j=0;
        while(i<a.size() && a[i].size()==0) i++;
    }
    
    int next() {
        int ret = a[i][j];
        if(j+1<a[i].size()) {
            j=j+1;
        } else {
            j=0;
            i+=1;
            while(i<a.size() && a[i].size()==0) i++;
        }
        cnt++;
        return ret;
    }
    
    bool hasNext() {
        return cnt<n;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */