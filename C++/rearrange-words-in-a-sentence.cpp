class Solution {
    //https://leetcode.com/problems/rearrange-words-in-a-sentence
    //article https://leetcode.com/problems/rearrange-words-in-a-sentence/discuss/4179267/C%2B%2B-O(NlogN)
public:
    string arrangeWords(string text) {
        vector<vector<int>> v; //{word_idx_start, word_idx_end, original_order}
        text.push_back(' ');
        int n = text.length(), L=0,R=0,order=0;
        text[0] = text[0]-'A' +'a';
        while(R<n) {
            if(text[R]!=' ')
                R++;
            else {
                v.push_back({L,R-L,order++});
                L=++R;
            }
        }
        
        sort(v.begin(), v.end(), [&](auto &lhs, auto &rhs) {
            return lhs[1] == rhs[1]?lhs[2] < rhs[2]:lhs[1] < rhs[1];
        });
        string ans;
        for(auto &w: v) {
            int m = w[0] + w[1];
            for(int i = w[0]; i<m;i++) ans.push_back(text[i]);  
            ans.push_back(' ');
        }
        ans.pop_back();
        ans[0] = ans[0]-'a'+'A';
        return ans;
    }
};