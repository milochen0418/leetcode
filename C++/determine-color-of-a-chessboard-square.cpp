class Solution {
    //https://leetcode.com/problems/determine-color-of-a-chessboard-square/
public:
    bool squareIsWhite(string coordinates) {
        /*
        char a = coordinates[0]-'a'+1;
        char b = coordinates[1]-'0';
        return (a+b)%2==1;
        */
        return (coordinates[0]-'a'+coordinates[1]-'0')%2==0;
    }
};