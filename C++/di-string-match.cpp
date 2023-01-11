class Solution {
    //https://leetcode.com/problems/di-string-match
public:
    vector<int> diStringMatch(string s) {
        vector<vector<int>> base={{0,0}};
        vector<int> A={0};
        int upcnt = 1;
        int downcnt = -1;
        int idx=1;
        for(auto &c: s) {
            if(c=='I') 
                A.push_back(upcnt++);
            else 
                A.push_back(downcnt--);
        }
        downcnt+=1;
        for(auto &i:A)i+=-1*downcnt;
        return A;
    }
};