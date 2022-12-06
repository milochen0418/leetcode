class Solution {
    //https://leetcode.com/problems/capitalize-the-title
public:
    string capitalizeTitle(string title) {
        int n = title.length();
        for(int i = 0;i<n;i++) {
            if (i==0 || title[i-1]==' ') {
                title[i] = Upper(title[i]);
                if(i+2>=n || title[i+1]==' ' || title[i+2]==' ') 
                    title[i] = Lower(title[i]);
            } else {
                title[i] = Lower(title[i]);
            }
        }
        return title;
    }
    char Upper(char c) { return 'a'<=c && c<='z'?c-'a'+'A':c; }
    char Lower(char c) { return 'A'<=c && c<='Z'?c-'A'+'a':c;}
};