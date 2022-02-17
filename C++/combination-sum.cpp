class Solution {
    // https://leetcode.com/problems/combination-sum
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        if(n==0) return ans;
        vector<int>& v = candidates;
        vector<int> a;
        int v_idx = 0;
        sort(v.begin(), v.end());
        combineSum(v,v_idx, a, target);
        return ans;
    }
    
    void combineSum(vector<int>& v,int& v_idx, vector<int>& a, int target ) {
        for(int i=v_idx;i<v.size();i++) {
            int val = v[i];
            if(val < target){
                a.push_back(val);
                //combineSum(v,v_idx, a, target-val);
                combineSum(v,i, a, target-val);
                a.pop_back();
                
            } else if(val == target) {
                a.push_back(val);
                ans.push_back(a);
                a.pop_back();
            } else {// case val > target
                return;
            }
        }
    }
};

/* testcase
[2,3,6,7]
7
[2,3,5]
8
[2]
1
[2,7,6,3,5,1]
9
*/