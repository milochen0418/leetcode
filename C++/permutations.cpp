class Solution {
    //https://leetcode.com/problems/permutations
public:
    //Logic of backtracking
    //a = [0,1,2,3]
    //swap(a[0],a[0])
    //a = [0,?,?,?]
    //recursive for tailed part [? ? ?] 
    //swap(a[0],a[0])
    
    //a = [0,1,2,3]
    //swap(a[0],a[1])
    //a = [1,?,?,?]
    //recursive for tailed part [? ? ?] 
    //swap(a[0],a[1])
    //a = [0,1,2,3]

    //a = [0,1,2,3]
    //swap(a[0],a[2])
    //a = [2,?,?,?]
    //recursive for tailed part [? ? ?] 
    //swap(a[0],a[2])
    //a = [0,1,2,3]
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans = vector<vector<int>>();
        per(ans, 0, nums);
        return ans;
    }
    void per(vector<vector<int>>& ans, int start_idx,  vector<int>& a) {
        if(start_idx == a.size()-1) {
            ans.push_back(a);
        } else {
            for(int i=start_idx; i<a.size();i++) {            
                swap(a[start_idx], a[i]);
                per(ans, start_idx+1, a);
                swap(a[start_idx], a[i]);
            }
        }
    }
};