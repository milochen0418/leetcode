class Solution {
    //https://leetcode.com/problems/cycle-length-queries-in-a-tree
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto &v:queries) ans.push_back(getLength(n,v[0],v[1]));
        return ans;
    }
    int getLength(int n, int a, int b) {
        int len = 1;//1 is edge length
        while(a!=b) {//use two-pointer to find out lowest common ancestor
            if(a<b) swap(a,b); 
            a=a/2;
            len++;            
        }
        return len;
    }
};