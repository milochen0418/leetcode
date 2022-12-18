class Solution {
    //https://leetcode.com/problems/cycle-length-queries-in-a-tree
    //article https://leetcode.com/problems/cycle-length-queries-in-a-tree/discuss/2924421/C%2B%2B-or-easy-10-lines-or-two-pointer
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto &v:queries) {
            int len=1;//1 is edge length
            while(v[0]!=v[1]) { //use two-pointer to find out lowest common ancestor
                (v[0]>v[1]?v[0]:v[1])/=2;//always get half of largest value. 
                len++;
            }
            ans.push_back(len);
        }
        return ans;
    }

    vector<int> cycleLengthQueries_v01(int n, vector<vector<int>>& queries) {
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