class Solution {
    //https://leetcode.com/problems/valid-word-square
public:
    bool validWordSquare(vector<string>& words) {
        int m = words.size();
        int n = 0;
        for(auto &w:words) 
            n = max(n,(int)w.length());
        int o = max(n,m);
        for(int k = 0;k<o;k++) {
            string row,col; 
            //make row
            for(int j = k;j<o;j++) {
                //words[k][j]
                char words_kj=' ';
                if(k<words.size() && j<words[k].size())
                    words_kj = words[k][j];
                row.push_back(words_kj);
            }
            //make col
            for(int i = k;i<o;i++) {
                char words_ik=' ';
                if(i<words.size() && k<words[i].size())
                    words_ik = words[i][k];
                col.push_back(words_ik);
            }
            if(row!=col) return false;
        }
        return true;
            
    }
};