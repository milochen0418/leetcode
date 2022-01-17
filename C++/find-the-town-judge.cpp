class Solution {
    //https://leetcode.com/problems/find-the-town-judge
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> judge_mp;
        unordered_map<int,int> body_mp;
        if(n==1) return 1;
        int candidate_judge = -1;
        for (auto pair: trust) {
            judge_mp[pair[1]] += 1; 
            body_mp[pair[0]] += 1; 
            if(judge_mp[pair[1]] == n-1) {
                candidate_judge = pair[1];
            }
        }
        
        if(candidate_judge != -1 && body_mp[candidate_judge]>0) return -1;
        return candidate_judge;
    }
};