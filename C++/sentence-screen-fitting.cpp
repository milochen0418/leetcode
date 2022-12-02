class Solution {
    //https://leetcode.com/problems/sentence-screen-fitting
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        vector<int> v;
        for(auto &s:sentence)v.push_back(s.length());
        int n = v.size();
        int row=0, col=0;
        int i = 0;
        while(row < rows) {
            int width = v[i%n];//width of word
            if(col+width > cols) {
                col=0;
                row++;
            } else {
                col+=(width+1);//+1 is mean space 1
                i=i+1;
            }
        }
        return i/n;
    }
};