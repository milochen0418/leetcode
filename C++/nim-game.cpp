class Solution {
    //https://leetcode.com/problems/nim-game
public:
    bool canWinNim(int n) {
        /*
        If A get stone so that to remain 4 stone for B, then B will lose
        because after B choosen 1,2 or 3, then the remaind 3,2,1 stones could finish by
        A last time.
        
        So the people who can make 4 remained stones to another one is the winner .
        
        
        When there are  5,6 and 7 stone that leaved by B, then A can win because 
        A can take 1,2 or 3 to make remained 4 stone for B. 
        Thus A need to make sure 8 stone happened in B and let B to choosen.
        
        A need to make sure she can leaved 4*n stone for B and then A can win.
        When the game start and A need to select first. 
        If there are 4*n stone for A to select, then A cannot make 4*(n-1).
        But B can make it happen after whatever A selected. 
        
        Thus. the root cause to make A to lose the game is n%4==0
        */
        return n%4!=0;        
    }
};