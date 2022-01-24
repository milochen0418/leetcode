class Solution {
    //https://leetcode.com/problems/detect-capital
public:
    bool detectCapitalUse(string word) {
        const char* str = word.c_str();
        int i = 0;
        bool shouldAllLowerCase = false;
        bool isFirstUpperCase = false;
        bool shouldAllUpperCase = false;
        while(str[i]!='\0') {
            char c = str[i];
            if(i==0) {
                if(c>='a' && c<='z') {
                    shouldAllLowerCase = true;
                    isFirstUpperCase = false; 
                } else {
                    shouldAllLowerCase = false;
                    isFirstUpperCase = true;
                }
            } else if(i==1){
                if(shouldAllLowerCase) {
                    if( c >= 'A' && c <= 'Z') {
                        return false;
                    }
                }
                if(isFirstUpperCase) {
                    if( c >= 'A' && c <= 'Z') {
                        shouldAllUpperCase = true;
                    } else {
                        shouldAllUpperCase = false;
                    }
                }
            } else {
                if(shouldAllLowerCase) {
                    if( c >= 'A' && c <= 'Z') {
                        return false;
                    }
                }
                if(shouldAllUpperCase) {
                    if( c >= 'a' && c <= 'z') {
                        return false;
                    }
                } else {
                    if( c >= 'A' && c <= 'Z') {
                        return false;
                    }
                }           
            }
            i++;
        }
        return true;
    }
};