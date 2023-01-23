class Solution {
    //https://leetcode.com/problems/find-the-town-judge
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> cntR = vector<int>(n+1,0);
        vector<int> cntL = vector<int>(n+1,0);
        for(auto &v:trust) {
            cntR[v[1]]++; //be trusted
            cntL[v[0]]++; //trust another one
        }
        for(int i = 1;i<n+1;i++) 
            if(cntR[i] == n-1 && cntL[i] == 0) return i;
        return -1;
    }

    int findJudge_v01(int n, vector<vector<int>>& trust) {
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