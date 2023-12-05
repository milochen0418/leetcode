class Solution {
    //https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices%2==1) return {};
        if(tomatoSlices/2<cheeseSlices) return {};
        if(tomatoSlices/4>cheeseSlices) return {};
        /*
        x+y = C
        4*x + 2*y = T 
        We need to find the answer for x,y
        2*C + 2x = T -> x = (T-2C)/2
        y = C-x
        */
        int x = (tomatoSlices - 2*cheeseSlices)/2;
        int y = cheeseSlices - x;
        return {x,y};
    }
};