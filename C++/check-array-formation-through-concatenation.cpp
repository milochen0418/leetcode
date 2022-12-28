class Solution {
    //https://leetcode.com/problems/check-array-formation-through-concatenation
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = 0;
        for(auto &p:pieces) n+=p.size();
        if(n!=arr.size())return false;
        vector<int> mp = vector<int>(101,0);//mp[val] is the idx s.t. pieces[ mp[val]][0] = val 
        for(int i = 0; i<pieces.size();i++) mp[pieces[i][0]]=i;
        int j2=0,j1 = mp[arr[0]];
        for(int i = 0;i<n;i++) {
            if(arr[i] != pieces[j1][j2++]) return false;
            if(j2==pieces[j1].size()) {
                if(i+1<n) j1=mp[arr[i+1]];
                j2=0;
            }
        }
        return true;
    }
};