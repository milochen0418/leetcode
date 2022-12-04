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
        
        vector<vector<int>> dp = vector<vector<int>>(cols+1, vector<int>(2,-1));
        int dp_idx = 0;
        int row_diff = 0;
        
        while(1) {
            
            if(i%n==0 && dp[dp_idx][0] != -1 ) {    
                printf("repeat in dp_idx = %d ", dp_idx);                
                int next_row = row + dp[dp_idx][0];
                int next_col = dp[dp_idx][1];
                int next_cur = next_row * cols + next_col;
                if(next_cur > rows*cols) break;
                    
                row_diff = 0;
                //row = next_row + dp[dp_idx][0];
                row = next_row;
                col = next_col; //col will be in [0..cols]
                dp_idx = col;
                //cur = row * cols + col;
                cur = row * cols + col;
                printf("with update cur = %d and update data dp_idx=%d, row=%d, col=%d\n", cur, dp_idx, row, col);
                ans++;
                continue;  
            } 
            
            int width = v[i%n];
            int next_col = col + (col!=0) + width;
            if(next_col>cols) {
                row++;
                row_diff++;
                col = width;
            } else {
                col = next_col;
            }
            cur = row*cols + col;
            if(cur > rows*cols) {
                break;
            }
            if((i+1)%n==0) {
                ans++;
                printf("call ans++ in step A, now ans=%d\n", ans);
            }
            i=i+1;
            
            if(i%n==0) {
                if(dp[dp_idx][0]==-1) {
                    printf("setup dp[dp_idx=%d][0] = %d, dp[dp_idx][1]=%d\n",dp_idx,row_diff, col );
                    dp[dp_idx][0] = row_diff;
                    dp[dp_idx][1] = col;
                }
                if(cur >= rows*cols) {
                    printf("\nbreak while in step 2.\n");
                    break;
                }
            }
        }   
        return ans;
        /* Current DP with the issue that Output = Expected + 1 for some case and I still don't know why.
["f","p","a"]
16
7
["f","p","a"]
17
7
["hello","world"]
6
8
["hello","world"]
7
8
["a", "bcd", "e"]
15
6
["a", "bcd", "e"]
14
6
["i","had","apple","pie"]
12
5
["i","had","apple","pie"]
13
5        
        */
    }

    int wordsTypingVer02(vector<string>& sentence, int rows, int cols) {
        //new simulate version without dp
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