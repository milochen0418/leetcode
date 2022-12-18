class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto &v:queries) ans.push_back(getLength(n,v[0],v[1]));
        return ans;
    }
    int getLength(int n, int a, int b) {
        int len = 1;//1 is edge length
        while(a!=b) {//use two-pointer to find out lowest common ancestor
            (a<b?b:a)/=2;//always get half of largest value. 
            len++;            
        }
        return len;
    }
};