class Solution {
    //https://leetcode.com/problems/sentence-screen-fitting
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        vector<int> v;
        int max_width = 0;
        for(auto &s:sentence){
            v.push_back(s.length());
            max_width = max(max_width, (int)s.length());
        }
        if(max_width > cols) return 0;
        
        int n=v.size(),ans=0,i=0, col=0, row=0, cur = 0;
        while(1) {
            int width = v[i%n];
            int next_col = col + (col!=0) + width;
            if(next_col>cols) {
                row++;
                col = width;
            } else {
                col = next_col;
            }
            cur = row*cols + col;
            if(cur > rows*cols) break;
            if((i+1)%n==0) ans++;
            i=i+1;
        }
        return ans;
    }
    
    int wordsTypingVer01(vector<string>& sentence, int rows, int cols) {
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