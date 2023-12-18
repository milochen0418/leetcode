class Solution {
    //https://leetcode.com/problems/alphabet-board-path
    //article https://leetcode.com/problems/alphabet-board-path/discuss/4418242/C%2B%2B-simple-19-lines
public:
    string alphabetBoardPath(string target) {
        string ans;
        vector<int> prev = {0,0};
        char prevc='a';
        for(auto &c: target) {
            vector<int> curr = {(c-'a')/5, (c-'a')%5};
            int rdiff = curr[0] - prev[0];
            int cdiff = curr[1] - prev[1];
            if(prevc == 'z') {
                for(int i =0;i<abs(rdiff);i++)ans.push_back(rdiff>0?'D':'U');
                for(int i =0;i<abs(cdiff);i++)ans.push_back(cdiff>0?'R':'L'); 
            } else {
                for(int i =0;i<abs(cdiff);i++)ans.push_back(cdiff>0?'R':'L');
                for(int i =0;i<abs(rdiff);i++)ans.push_back(rdiff>0?'D':'U');
            }
            ans.push_back('!');
            prev = curr;
            prevc = c;
        }
        return ans;
    }
};

