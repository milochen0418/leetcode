class Solution {
    //https://leetcode.com/problems/text-justification
    //Refer solution from https://github.com/yuanhui-yang/LeetCode/blob/master/Algorithms/text-justification.cpp
    //But still not thinking and see solution. just rewrite first.
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int sz = words.size();
        int i =0;
        
        while(i<sz) {
            int j = i;
            int a = words[i].size();
            int b = words[i].size();
            while(i+1 < sz && a + words[i+1].size() + 1 <= maxWidth) {
                a += words[i+1].size() + 1;
                b += words[i+1].size();
                i++;
            }
            string s;
            if(i+1 == sz){
                s.append(words[j]);
                ++j;
                while(j<=i){
                    s.push_back(' ');
                    s.append(words[j]);
                    ++j;
                }
            }
            else if(i == j) {
                s.append(words[i]);
            } 
            else {                
                int x = (maxWidth - b) / (i-j);
                int y = (maxWidth - b) % (i-j);
                s.append(words[j]);
                ++j;
                while(j<=i){
                    if(y>0) {
                        --y;
                        s.push_back(' ');
                    }
                    s.append(string(x, ' '));
                    s.append(words[j]);
                    ++j;
                }
            }
            while(s.size() < maxWidth) {
                s.push_back(' ');
            }
            result.push_back(s);
            i++;
        }
        return result;
    }
};